def longest(s):
    if(len(s) == 0):
        return 0
    maximum = 0
    start_index = 0
    hash_map = {}
    for i in range(len(s)):
        if(s[i] in hash_map):
            maximum = max(maximum,len(hash_map))
            while s[i] in hash_map:
                del hash_map[s[start_index]]
                start_index += 1
        hash_map[s[i]] = i
    return max(maximum,len(hash_map))

s = input("Enter a String")
print(longest(s))
