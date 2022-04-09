# nums=[7,7,7,7,7]
nums = [0,1,2,2,2]
hash_map = {i:{} for i in range(len(nums))}
ans = 0
for i in range(1,len(nums),1):
    for j in range(i):
        cd = nums[i]-nums[j]
        # ans += hash_map[j].get(cd,0)
        # hash_map[i][cd] = hash_map[i].get(cd,0) + hash_map[j].get(cd,0) + 1
        if(cd in hash_map[j]):
            hash_map[i][cd] = hash_map[i].get(cd,0) + hash_map[j][cd]+1
            ans += hash_map[j][cd]
        else:
            hash_map[i][cd] = hash_map[i][cd]+1 if cd in hash_map[i] else 1
print(hash_map)
print(ans)