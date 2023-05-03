for _ in range(int(input())):
    n = int(input())
    prices = list(map(int,input().split()))
    profit = 0
    max_price = prices[-1]
    for i in range(n-2,-1,-1):
        if max_price < prices[i]:
            max_price = prices[i]
        else:
            profit += max_price - prices[i]
    print(profit)