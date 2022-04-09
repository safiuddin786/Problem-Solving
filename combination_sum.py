def check(candidates,i,target,result,temp):
    if(i==len(candidates)):
        return
    elif(target == 0):
        result.append(list(temp))
        return
    else:
        if(candidates[i]<=target):
            temp.append(candidates[i])
            check(candidates,i,target-candidates[i],result,temp)
            temp.pop()
        check(candidates,i+1,target,result,temp)
candidates = [2,3,5]
result = []
temp = []
target = 8
check(candidates,0,target,result,temp)
print(result)