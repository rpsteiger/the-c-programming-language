#!/usr/bin/python

import sys, os


if len(sys.argv) < 2:
    raise ValueError('no program name suppllied!')

os.system(f'gcc -ansi {sys.argv[1]}.c -o {sys.argv[1]}.out')
os.system(f'./{sys.argv[1]}.out')        