import sys
input = sys.stdin.readline

coins = [500, 100, 50, 10, 5, 1]
paid_money = int(input())
temp = 1000 - paid_money
ans = 0
for coin in coins:
    ans += temp//coin
    temp %= coin
print(ans)