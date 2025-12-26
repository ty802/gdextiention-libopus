#!/bin/env python3
import glob
import os
import sys
import subprocess
import platform
from pathlib import Path
os.chdir(sys.argv[1])
subprocess.run([sys.argv[2]], stdout=sys.stdout,
               stdin=sys.stdin)
if platform.system() == 'Windows':
    res = glob.glob("bin\\*.lib", recursive=True)
else:
    res = glob.glob("bin/*.a", recursive=True)
path = res.pop(0)
os.rename(path, Path(sys.argv[3]) / "lib.a")
(Path(sys.argv[1]) / "godot-cpp-generated").touch()
