import sys
x = int(input())

dp = [[0,[]] for _ in range(x+1)]
dp[1][0] = 0
dp[1][1] = [1]

for i in range(2, x+1):
    dp[i][0] = dp[i-1][0]+1
    dp[i][1] = dp[i-1][1]+[i]
    if i % 3 == 0:
        if(dp[i][0]>dp[i//3][0]+1):
            dp[i][0] = dp[i//3][0]+1
            dp[i][1] = dp[i//3][1]+[i]
    if i % 2 == 0:
        if (dp[i][0] > dp[i//2][0]+1):
            dp[i][0] = dp[i//2][0]+1
            dp[i][1] = dp[i//2][1]+[i]

print(dp[x][0])
for i in dp[x][1][::-1]:
    print(i,sep=' ')
