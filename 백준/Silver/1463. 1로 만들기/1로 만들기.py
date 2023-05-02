import sys
x = int(input())

cnt = 0
num = 1

dp = [sys.maxsize]*1000001
dp[1] = 0

for i in range(1,x+1):
    if i % 3 == 0:
        dp[i] = min(dp[i//3]+1, dp[i-1]+1)
    if i % 2 == 0:
        dp[i] = min(dp[i//2]+1, dp[i])
    dp[i] = min(dp[i], dp[i-1]+1)

print(dp[x])
