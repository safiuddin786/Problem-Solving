l = [10, 20, 1, 19, 20, 10, 8, 100, 98, 87]
# insert elements into the sorted list
for i in range(1, len(l)):
    selected = l[i]
    j = i
    while(j > 0 and selected < l[j-1]):
        l[j] = l[j-1]
        j-=1
    l[j] = selected
print(l)
