# second max of unique array O(n)
l = [int(i) for i in input().split()] # length is n
l.remove(max(l))
print(max(l))