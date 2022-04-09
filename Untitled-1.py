import math
A = [3,1,2,6,4,5,9]
a0 = 0
a1 = 0
a2 = 0
count = 0
for i in range(len(A)):
    if(A[i] % 3 == 0):
        a0 += 1
        if(i % 3 != 0):
            count += 1
    elif(A[i] % 3 == 1):
        a1 += 1
        if(i % 3 != 1):
            count += 1
    else:
        a2 += 1
        if(i % 3 != 2):
            count += 1
if(len(A)%3 == 0):
    if(a0 == a1 == a2):
        print(math.ceil(count/2))
    else:
        print('Not Possible')
elif(len(A)%3 == 1):
    if((a0-1) == a1 == a2):
        print(math.ceil(count/2))
    else:
        print('Not Possible')
else:
    if(a0 == a1 == (a2+1)):
        print(math.ceil(count/2))
    else:
        print('Not Possible')
