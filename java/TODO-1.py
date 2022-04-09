def LargestFour(arr):
    n = len(arr)
    sum = 0
    if(n < 4):
        for a in arr:
            sum += a
    for i in range(4):
        for j in range(n-1):
            if(arr[j] > arr[j+1]):
                arr[j],arr[j+1] = arr[j+1],arr[j]
    
    for i in range(4):
        sum += arr[n-i-1]
    return sum

arr = [1,1,1,-5]
print(LargestFour(arr))