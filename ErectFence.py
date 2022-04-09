def slope(x,z,y): #x[x1][x2] lastlist=z[z1][z2] y[y1][y2]
    if((z[0]-x[0]) != 0 and (y[0]-z[0]) != 0):
        return ((y[1]-z[1])/(y[0]-z[0]) > (z[1]-x[1])/(z[0]-x[0]))
    elif(y[0]-z[0] == 0):
        if(y[1]-z[1] > 0):
            return True
        else:
            return False
    elif(z[0]-x[0] == 0):
        if(z[0]-x[0]):
            return False
        else:
            return True
    else:
        return False
trees = [[3,0],[4,0],[5,0],[6,1],[7,2],[7,3],[7,4],[6,5],[5,5],[4,5],[3,5],[2,5],[1,4],[1,3],[1,2],[2,1],[4,2],[0,3]]
trees.sort()
j = 0
jd = 0
result = [trees[0]]
down_res = []
for t in range(1,len(trees),1):
    if(trees[t][1] >= trees[0][1]):
        if(len(result) > 1 and trees[j][1] >= trees[t][1]):
            if(slope(result[-1],result[-2],trees[t]) == False):
                result.append(trees[t]) #append
            else:
                while(slope(result[-1],result[-2],trees[t])): #pop
                    result.pop()
                result.append(trees[t])
        else:
            while(len(result) > 1 and slope(result[-1],result[-2],trees[t])):
                result.pop()
            result.append(trees[t])
            j = t
    else:
        if(trees[t][1] < trees[0][1]):
            if(trees[jd][1] <= trees[t][1]):
                if(len(down_res) > 1 and slope(down_res[-1],down_res[-2],trees[t])):
                    down_res.append(trees[t])    #append
                else:
                    while(len(down_res) > 1 and slope(down_res[-1],down_res[-2],trees[t]) == False):       #pop
                        down_res.pop()
                    down_res.append(trees[t])
            else:
                while(len(down_res) > 1 and slope(down_res[-1],down_res[-2],trees[t]) == False):     #shift j,k
                    down_res.pop()
                down_res.append(trees[t])
                jd = t
result.extend(down_res)
print(result)




# trees = [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
# trees.sort()
# i = 0
# j = 0
# k = 0
# result = [trees[0]]
# for t in range(1,len(trees),1):
#     if(trees[t][1] >= trees[i][1]):
#         if(trees[j][1] >= trees[t][1]):
#             if(trees[k][1] > trees[t][1]):
#                 result.append(trees[t])
#                 k = t #append
#             else:
#                 while(result[-1][1] < trees[t][1]): #pop
#                     result.pop()
#                 result.append(trees[t])
#                 k = t
#         else:
#             while(len(result) > 1 and (result[-1][1] < trees[t][1] and result[-1][1]+1 != trees[t][1])):
#                 result.pop()
#             result.append(trees[t])
#             j = t
#             k = j
# i = 0
# j = 0
# k = 0
# down_res = []
# for t in range(1,len(trees),1):
#     if(trees[t][1] < trees[i][1]):
#         if(trees[j][1] <= trees[t][1]):
#             if(trees[k][1] < trees[t][1]):
#                 down_res.append(trees[t])
#                 k = t       #append
#             else:
#                 while(down_res[-1][1] > trees[t][1]):       #pop
#                     down_res.pop()
#                 down_res.append(trees[t])
#                 k = t
#         else:
#             while(len(down_res) > 0 and down_res[-1][1] > trees[t][1] and result[-1][1] - 1 != trees[t][1]):     #shift j,k
#                 down_res.pop()
#             down_res.append(trees[t])
#             j = t
#             k = j
# result.extend(down_res)
# print(result)