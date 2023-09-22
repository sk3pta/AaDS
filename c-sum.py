import re


nums = []
with open("input") as file:
    f = file.read()
    for x in re.findall(r'-?[0-9]+',f):
        nums.append(int(x))
    
with open("output",'w') as file:
    file.write(str(sum(nums) % 256))

print(nums)