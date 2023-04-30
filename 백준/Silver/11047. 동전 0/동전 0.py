n, k = map(int,input().split())
coins = []

for _ in range(n):
    coins.append(int(input()))
cnt = 0

for i in range(n-1, -1,-1):
    if k == 0:
        break
    while k >= coins[i]:
        tmp = k//coins[i]
        k -= coins[i]*tmp
        cnt += tmp

print(cnt)
