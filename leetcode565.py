nums = [5,4,0,3,1,6,2]
maximum = 0
# visited = {}
for i in range(len(nums)):
    count = 0
    if(nums[i] == -1):
        continue
    else:
        j = i
        while(nums[j] != -1):
            k = j
            j = nums[j]
            nums[k] = -1
            count += 1
    maximum = max(count,maximum)
print(maximum)
