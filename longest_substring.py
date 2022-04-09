# # longest substring using recursion
# def longest(s,count):
#     if(len(s) > 0):
#         if(len(s) == 1):
#             return count
#         if(ord(s[0]) < ord(s[1])):
#             count += 1
#             return longest(s[1:],count)
#         else:
#             return max(count,longest(s[1:],1))

# s = input("Enter the String")
# print(longest(s,1))

# longest substring using iterative method
def longest(s):
    if(len(s) == 0):
        return 0
    count = 1
    maximum = 0
    for i in range(1,len(s),1):
        if(ord(s[i-1]) < ord(s[i])):
            count += 1
        else:
            maximum = max(maximum,count)
            count = 1
    return max(maximum,count)
s = input("Enter a string")
print(longest(s))