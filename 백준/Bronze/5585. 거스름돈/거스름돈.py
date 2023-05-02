n = int(input())
n = 1000-n

cnt = 0
coins = [500, 100, 50, 10, 5, 1]

for coin in coins:
    cnt += n//coin
    n %= coin
print(cnt)