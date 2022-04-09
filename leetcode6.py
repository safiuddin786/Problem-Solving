s = 'AB'
s1 = ''
n = 1
for i in range(n):
    if(i < n-1 and i != 0):
        s1 += s[i]
        count1 = i + (n-i)*2 - 2
        count2 = count1 + 2*i
        while count1 < len(s) and count2 < len(s):
            s1 += s[count1]
            s1 += s[count2]
            count1 = count2 + (n-i)*2 - 2
            count2 = count1 + 2*i
        if(count1 < len(s)):
            s1 += s[count1]
        if(count2 < len(s)):
            s1 += s[count2]
    else:
        s1 += s[i]
        count = i + n*2 - 2
        while count < len(s):
            s1 += s[count]
            count += n*2 - 2
print(s1)