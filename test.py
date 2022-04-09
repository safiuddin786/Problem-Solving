n = 3999
d = [
    (n//(pow(10,i)))%10 for i in range(4)
]
roman=['I','V','X','L','C','D','M']
s = ''
for i in range(4):
    if(d[i]):
        if(d[i] >= 1 and d[i] < 5):
            for j in range(4):
                if(1+j == d[i]):
                    if(j==3):
                        s = roman[i*2]+roman[i*2+1] + s
                    else:
                        s = roman[i*2]*(j+1) + s
        elif(d[i] >= 5 and d[i] < 10):
            for j in range(5):
                if(5+j == d[i]):
                    if(j==4):
                        s = roman[i*2]+roman[i*2+2] + s
                    else:
                        s = roman[i*2+1]+roman[i*2]*j + s
print(s)