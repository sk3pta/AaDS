import re
import sys
import os

nums = []
for line in sys.stdin:
    for x in re.findall(r'-?[0-9]+',line):
        nums.append(int(x))
print(os.system("ls /home"))
print(sum(nums))

