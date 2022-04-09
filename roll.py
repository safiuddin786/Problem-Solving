
# def getUnordered(A,B):
#     A = str(A)
#     B = str(B)
#     hash_map = {}
#     result = []
#     for i in range(len(A)):
#         if(A[i] in hash_map):
#             hash_map[A[i]] += 1
#         else:
#             hash_map[A[i]] = 1
#     for i in range(len(B)):
#         for key,val in hash_map.items():
#             if(int(B[i]) == val):
#                 result.append(int(key))
#     return result
# print(getUnordered(160401,234))
