def fib1(n):
    if n < 2:
        return n
    if arr[n]:
        return arr[n]
    else:
        arr[n] = fib1(n-1) + fib1(n-2)
        return arr[n]


def fib2(n):
    print()


N = int(input())
arr = [0]*(N+1)
print(fib1(N))
