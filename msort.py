a = [int(i) for i in input('Enter the array: ').split()]
# def merge_sort(a):
#     if(len(a) > 1):
#         m = len(a)//2
#         l = a[:m]
#         r = a[m:]
#         merge_sort(l)
#         merge_sort(r)
#         i = j = k = 0
#         while i < len(l) and j < len(r):
#             if(l[i] < r[j]):
#                 a[k] = l[i]
#                 i = i + 1
#             else:
#                 a[k] = r[j]
#                 j += 1
#             k += 1
#         # check end
#         while i < len(l):
#             a[k] = l[i]
#             k += 1
#             i += 1
#         while j < len(r):
#             a[k] = r[j]
#             k += 1
#             j += 1
def merge_sort(a):
    if(len(a) > 1):
        m = len(a)//2
        l = a[:m]
        r = a[m:]

        merge_sort(l)
        merge_sort(r)

        i = j = k = 0
        while(i < len(l) and j < len(r)):
            if(l[i] < r[j]):
                a[k] = l[i]
                i += 1
            else:
                a[k] = r[j]
                j += 1
            k += 1
        if(i < len(l)):
            a[k:] = l[i:]
        else:
            a[k:] = r[j:]
merge_sort(a)
print(a)