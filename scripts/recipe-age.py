#!/usr/bin/env python3

import sys
import argparse
import os
import subprocess
import shutil
import glob
import json

from collections import OrderedDict
import datetime

class AgeVersion(object):
    def __init__(self):
        default_rrs_data = os.path.abspath(os.path.join(os.path.dirname(sys.argv[0]), 'rrs-data'))
        parser = argparse.ArgumentParser(
            description="Report recipe age based on RRS",
            epilog="Use %(prog)s --help to get help")
        parser.add_argument("-r", "--rrs-data",
            help = "Specify rrs-data dir, default: rrs-data",
            action="store", dest="rrs_data", default=default_rrs_data)
        parser.add_argument("-o", "--outdir",
            help = "Specify outdir, default: recipe-age",
            action="store", dest="outdir", default="recipe-age")
        parser.add_argument("-s", "--sbom",
            help = "Specify spdx/sbom, only check the recipes from sbom",
            action="store", dest="sbom", default='')

        self.args = parser.parse_args()

        if not os.path.exists(self.args.outdir):
            os.makedirs(self.args.outdir)

        self.recipes = set()
        self.recipes_found = set()

    def main(self):
        if self.args.sbom:
            self.get_recipes()
        self.read_rrs_data()

    def get_recipes(self):
        unpack_dir = os.path.join(self.args.outdir, 'sbom')
        shutil.rmtree(unpack_dir, ignore_errors=True)
        os.makedirs(unpack_dir)
        if '.tar.' in self.args.sbom:
            cmd = 'tar xf %s -C %s' % (self.args.sbom, unpack_dir)
            print('Running %s' % cmd)
            subprocess.check_output(cmd, shell=True).decode('utf-8')
            recipes = glob.glob('%s/recipe-*.spdx.json' % unpack_dir)
            for r in recipes:
                recipe = os.path.basename(r)[7:-10]
                self.recipes.add(recipe)
        elif self.args.sbom.endswith('.json'):
            with open(self.args.sbom) as f:
                data = json.load(f)
                for _, v in data.items():
                    if isinstance(v, list):
                        for v_dict in v:
                            for k1, v1 in v_dict.items():
                                if k1 == 'name' and 'do_create_spdx:recipe' in v1:
                                    self.recipes.add(v1.replace(':do_create_spdx:recipe', ''))
        else:
            raise Exception('Unsuported spdx file %s' % self.args.sbom)

    def read_rrs_data(self):
        print('Reading rrs data from %s' % self.args.rrs_data)
        layers = glob.glob('%s/*.txt' % self.args.rrs_data)
        if not layers:
            raise Exception('Failed to find rrs data from %s' % self.args.rrs_data)
        header = ["Recipe,Layer,Current Version,Upstream Version,Status,Last Update,Age(days)"]
        outlines = []
        outlines_old_updated = []
        outlines_old_not_updated = []
        outlines_packagegroup_image = []
        outline = ''
        for layer in layers:
            layername = os.path.basename(layer)[:-4]
            with open(layer) as f:
                for line in f:
                    if line.startswith('*'):
                        line = line[2:]
                        begin = True
                        line_split = line.split()
                        recipe = line_split[0]
                        current_version = line_split[1]
                        upstream_version = line_split[2]
                        if len(line_split) > 3:
                            status = ' '.join(line_split[3:])
                        else:
                            status = 'Unknown'
                    if begin:
                        last_update = 'Unknown'
                        line_strip = line.strip()
                        if line_strip.startswith('- '):
                            last_update = line.split()[-1]
                            begin = False
                            recipes_list = []
                            if self.recipes:
                                recipes_check = [recipe]
                                if not (recipe.endswith('-native') and recipe.startswith('nativesdk-')):
                                    recipes_check.append('%s-native' % recipe)
                                    recipes_check.append('nativesdk-%s' % recipe)
                                for recipe_check in recipes_check:
                                    if recipe_check in self.recipes:
                                        recipes_list.append(recipe_check)
                                        self.recipes_found.add(recipe_check)
                                if not recipes_list:
                                    continue

                            if not recipes_list:
                                recipes_list = [recipe]

                            for recipe in recipes_list:
                                outline = ('%s,%s,%s,%s,%s' % (recipe, layername, current_version, upstream_version, status))
                                if 'Initial import ' in line_strip:
                                    outline += ',Initial import on %s,Unknown' % last_update
                                else:
                                    last_update_split = last_update.split('-')
                                    date1 = datetime.datetime(int(last_update_split[0]), int(last_update_split[1]), int(last_update_split[2]))
                                    age = (datetime.datetime.now() - date1).days
                                    outline += ',%s,%s' % (last_update, age)
                                    if age > 365:
                                        if not ('packagegroup-' in outline or '-image-' in outline):
                                            if 'Up-to-date' in outline:
                                                outlines_old_updated.append(outline)
                                            else:
                                                outlines_old_not_updated.append(outline)
                                outlines.append(outline)

        outlines.sort()
        outlines = header + outlines
        outfile = os.path.join(self.args.outdir, 'all_recipes.csv')
        print('Saving results to %s' % outfile)
        with open(outfile, 'w') as f:
            f.write('%s\n' % '\n'.join(outlines))

        for lines in (outlines_old_updated, outlines_old_not_updated):
            if len(lines) > 0:
                if lines == outlines_old_updated:
                    outfile = os.path.join(self.args.outdir, 'recipes_older_than_1year_but_updated.csv')
                    header_new = ["The following recipes are older than 1year but updated"] + header
                else:
                    header_new = ["The following recipes are older than 1year but not updated"] + header
                    outfile = os.path.join(self.args.outdir, 'recipes_older_than_1year_but_not_updated.csv')
                lines = header_new + lines
                print('Copying recipes to %s' % outfile)
                with open(outfile, 'w') as f:
                    f.write('%s\n' % '\n'.join(lines))

        if self.recipes:
            remaining = self.recipes - self.recipes_found
            if remaining:
                notfound = os.path.join(self.args.outdir, "recipes_not_found.txt")
                print("WARNING: Check %s for the recipes can't be found in rrs!" % notfound, file=sys.stderr)
                with open(notfound, 'w') as f:
                    f.write('%s\n' % '\n'.join(sorted(remaining)))
            else:
                print("All the recipes from sbom are found.")

if __name__ == "__main__":
    try:
        age = AgeVersion()
        ret = age.main()
    except Exception as esc:
        ret = 1
        import traceback
        traceback.print_exc()

    sys.exit(ret)
