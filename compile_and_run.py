#!/usr/bin/python

import sys, os


if len(sys.argv) < 2:
    raise ValueError("no program name suppllied!")

os.system(f"gcc {sys.argv[1]}.c -lm -g -std=c99")
os.system(f"./{sys.argv[1]}.out")
