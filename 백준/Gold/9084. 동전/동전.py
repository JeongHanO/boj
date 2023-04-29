import sys
t = int(input())

for _ in range(t):
    n = int(input())
    coins = list(map(int, input().split()))
    m = int(input())
    lst = [0]*(m+1)
    lst[0] = 1
    for coin in coins:
        for i in range(1, m+1):
            if i>=coin:
                lst[i] += lst[i-coin]
    print(lst[-1])