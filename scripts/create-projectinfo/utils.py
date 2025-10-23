import subprocess
import logging
import shlex

default_logger = logging.getLogger('utils')
default_logger.setLevel(logging.INFO)

def run_cmd(cmd_args, logger=default_logger, cwd=''):
    if isinstance(cmd_args, str):
        cmd_args = shlex.split(cmd_args)

    logger.debug('Running %s' % ' '.join(cmd_args))

    try:
        if cwd:
            output = subprocess.check_output(cmd_args, stderr=subprocess.STDOUT, text=True, cwd=cwd)
        else:
            output = subprocess.check_output(cmd_args, stderr=subprocess.STDOUT, text=True)
        logger.debug('output: %s' % output)
    except subprocess.CalledProcessError as e:
        raise Exception("%s\n%s" % (str(e), e.output))
    except (OSError, FileNotFoundError) as e:
        raise Exception("Command execution failed: %s" % str(e))

    return output

def set_logger(logger):
    logger.setLevel(logging.DEBUG)
    class ColorFormatter(logging.Formatter):
        FORMAT = ("$BOLD%(name)-s$RESET - %(levelname)s: %(message)s")

        BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE = list(range(8))

        RESET_SEQ = "\033[0m"
        COLOR_SEQ = "\033[1;%dm"
        BOLD_SEQ = "\033[1m"

        COLORS = {
            'WARNING': YELLOW,
            'INFO': GREEN,
            'DEBUG': BLUE,
            'ERROR': RED
        }

        def formatter_msg(self, msg, use_color = True):
            if use_color:
                msg = msg.replace("$RESET", self.RESET_SEQ).replace("$BOLD", self.BOLD_SEQ)
            else:
                msg = msg.replace("$RESET", "").replace("$BOLD", "")
            return msg

        def __init__(self, use_color=True):
            msg = self.formatter_msg(self.FORMAT, use_color)
            logging.Formatter.__init__(self, msg)
            self.use_color = use_color

        def format(self, record):
            levelname = record.levelname
            if self.use_color and levelname in self.COLORS:
                fore_color = 30 + self.COLORS[levelname]
                levelname_color = self.COLOR_SEQ % fore_color + levelname + self.RESET_SEQ
                record.levelname = levelname_color
            return logging.Formatter.format(self, record)

    # create console handler and set level to debug
    ch = logging.StreamHandler()
    ch.setLevel(logging.DEBUG)
    ch.setFormatter(ColorFormatter())
    logger.addHandler(ch)

set_logger(default_logger)
