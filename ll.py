# check subsequence
def check(a,b):
    i = 0
    j = 0
    while i < len(a) and j < len(b):
        if(a[i] == b[j]):
            i += 1
            j += 1
        else:
            j += 1
    if(i == len(a)):
        return True
    else:
        return False
l = ['aa','aaa','aaa','c','cca']
maximum = -1
same = False
for i in range(len(l)):
    for j in range(len(l)):
        if(i!=j):
            if(check(l[i],l[j])):
                same = True
    if(len(l[i]) > maximum and same == False):
        maximum = len(l[i])
    same = False
print(maximum)