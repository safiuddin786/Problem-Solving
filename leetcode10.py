def re(s,p):
    any_char = False
    same_char = ''
    i = 0
    j = 0
    while j < len(p) and i < len(s):
        if(p[j] == '.'):
            any_char = True
            i += 1
            j += 1
        elif(p[j] == '*'):
            if(any_char):
                if(j+1 < len(p)):
                    j += 1
                    while i < len(s) and p[j] != s[i]:
                        i += 1
                    if(i == len(s)):
                        return False
                else:
                    return True
            else:
                if(j < 1):
                    j += 1
                    continue
                same_char = p[j-1]
                if(j+1 < len(p)):
                    j += 1
                    while i < len(s) and s[i] == same_char and p[j] != s[i]:
                        i += 1
            any_char = False
        else:
            if(s[i] == p[j]):
                i += 1
                j += 1
            elif(j+1 < len(p) and p[j+1] == '*'):
                j += 1
            else:
                return False
            any_char = False
    while j < len(p) and p[j] == '*':
        j += 1
    if(i == len(s) and j == len(p)):
        return True
    else:
        return False
s = "aaaa"
p = "a*a"
print(re(s,p))