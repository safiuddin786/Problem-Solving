# HeapSort
a = [int(i) for i in input('Enter the array').split()]
def heapify(a,index):
    l = 2*index + 1
    r = 2*index + 2
    smallest = index
    if(l < len(a) and a[l] < a[index]):
        smallest = l
    if(r < len(a) and a[r] < a[smallest]):
        smallest = r
    if(index != smallest):
        a[index],a[smallest] = a[smallest],a[index]
        heapify(a,smallest)
def heapsort(a,output):
    if(len(a) > 1):
        output.append(a[0])
        a[0] = a.pop()
        # heapify after pop
        heapify(a,0)
        # recursive call to heapsort
        heapsort(a,output)
    elif(len(a) > 0):
        output.append(a[0])
    return output

# build heap
n = len(a)
for i in range((n//2)-1,-1,-1):
    heapify(a,i)
output = []
results = heapsort(a,output)
print(results)