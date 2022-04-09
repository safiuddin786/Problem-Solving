# # fibonachi using recursion
# def fib(n):
#     if(n==1 or n==2):
#         return 1
#     else:
#         return fib(n-1) + fib(n-2)
# n = int(input("Enter the postion"))
# print(fib(n))

# # fibonachi using mem
def fib(n,mem):
    if(mem[n-1] != -1):
        return mem[n-1]
    if(n==1 or n==2):
        result = 1
    else:
        result = fib(n-1,mem) + fib(n-2,mem)
    mem[n-1] = result
    return result
n = int(input("Enter the postion"))
mem = [-1 for i in range(n)]
print(fib(n,mem))

# # fibonachi using bottomup or iterative
# def fib(n,a):
#     if(n==1 or n==2):
#         return 1
#     a.extend([1,1])
#     for i in range(2,n,1):
#         a.append(a[i-1] + a[i-2])
#     return a[n-1]
# n = int(input("Enter the postion"))
# a = []
# print(fib(n,a))