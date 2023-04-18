import sys
import heapq

input = sys.stdin.readline

# 큰 수는 나중에 섞는 게 이득임
# 그럼 작은 수 먼저 뽑아서 더하면 될듯?
n = int(input())

lst = []

for _ in range(n):
    heapq.heappush(lst, int(input()))

if n == 1:
    print(0)
    quit()

res = 0

while len(lst) > 1:
    s = heapq.heappop(lst) + heapq.heappop(lst)
    res += s
    heapq.heappush(lst, s)

print(res)
