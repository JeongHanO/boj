n, k = map(int,input().split())
coins = []

for _ in range(n):
    coins.append(int(input()))

cnt = 0
for i in range(n-1, -1,-1):
    while k >= coins[i]:
        cnt += k//coins[i]
        k = k%coins[i]

print(cnt)
