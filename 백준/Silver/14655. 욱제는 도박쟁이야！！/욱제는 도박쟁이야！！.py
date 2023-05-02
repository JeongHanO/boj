import sys
n = int(input())

fir = list(map(int, input().split()))
sec = list(map(int, input().split()))
ans = 0
for i in fir:
    ans += abs(i)

print(2*ans)