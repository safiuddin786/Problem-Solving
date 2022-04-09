n = int(input())
a = int(input())
b = int(input())
c = int(input())
d = int(input())
# hash_map = {}
# same_value = 'none'
# for i in range(n):
#     hash_map[b+i*a] = i
# for i in range(n):
#     if(d+c*(i+1) in hash_map):
#         same_value = str(d+c*(i+1))
#         break
# if(same_value == 'none'):
#     print("No same amount of fuel found")
# else:
#     print(same_value)
for i in range(n):
    temp = (b+i*a-d)/c
    if(temp%1 == 0 and (1<=temp<=n)):
        print(b+i*a)
        break
# 50 20 2 9 19