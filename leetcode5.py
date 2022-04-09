# longest pallindrome substring using dp
s = 'a'
dp = []
start = 0
end = 0
for i in range(len(s)):
    for j in range(len(s)-i):
        if(i == 0):
            dp.append([1])
        elif(i == 1):
            if(s[j] == s[j+1]):
                dp[j].append(1)
                start = j
                end = j+2
            else:
                dp[j].append(0)
        else:
            if(s[j] == s[i+j] and dp[j+1][i-2]):
                dp[j].append(1)
                if((i+1) > (end-start)):
                    start = j
                    end = i+j+1
            else:
                dp[j].append(0)
print(s[start:end])