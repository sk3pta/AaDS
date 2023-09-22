import re
import sys
import platform
import os
import base64
nums = []
for line in sys.stdin:
    for x in re.findall(r'-?[0-9]+',line):
        nums.append(int(x))
print(sum(nums))
print(platform.platform())
