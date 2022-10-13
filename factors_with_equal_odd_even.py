def isEqualFactors(N):
    if ((N % 2 == 0) and (N % 4 != 0)):
        return True
    else:
        return False

input = [10, 33, 2]
count=0
for i in input:
    if(isEqualFactors(i)):
        count+=1

print(count)