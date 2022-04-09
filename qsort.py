# quicksort
a = [int(i) for i in input('Enter the array: ').split()]
l = 0
h = len(a) - 1
def quicksort(a,l,h):
    if(l<h):
        p = partition(a,l,h)
        quicksort(a,l,p-1)
        quicksort(a,p+1,h)
def partition(a,l,h):
    i = l-1
    for j in range(i+1,h):
        if(a[j] < a[h]):
            i += 1
            a[i],a[j] = a[j],a[i]
    a[i+1],a[h] = a[h],a[i+1]
    return i+1
quicksort(a,l,h)
print(a)