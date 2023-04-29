def fib1(n):  # top-down
    if n < 2:
        return n
    if arr1[n]:
        return arr1[n]
    else:
        arr1[n] = fib1(n-1) + fib1(n-2)
        return arr1[n]


def fib2(n):  # bottom-up
    
    arr2.append(0)
    arr2.append(1)
    for i in range(2, n+1):
        arr2.append(arr2[i-1]+arr2[i-2])
    return arr2[n]


N = int(input())
arr1 = [0]*(N+1)
arr2 = []
# print(fib1(N))
print(fib2(N))
