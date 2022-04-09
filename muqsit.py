# muqsit did haggu in this
n = int(input("Enter the number : "))
result = []
#  stack
temp = list([1])
result.extend(temp)
for i in range(n-1):
    j = len(temp)-1
    while(j >= 0):
        if temp[j] != 9:
            temp[j]+=1
            result.extend(temp)
            break
        # if its 9 then change
        else:
            if j==0:
                temp[j]=0
                temp.insert(0,1)
                result.extend(temp)
            else:
                temp[j]=0
            j-=1
print(result)