import sys
from collections import deque
input = sys.stdin.readline


n = int(input())
m = int(input())
toy = [[]for _ in range(n+1)]
v = [0]*(n+1)

for _ in range(m):
    a, b, c = map(int, input().split())
    toy[a].append((b, c))
    v[b] += 1

basic = []
for i in range(1, n+1):
    if not len(toy[i]):
        basic.append(i)

q = deque()
ans = []

for i in range(n, 0, -1):
    if not v[i]:
        q.append(i)


parts = [0]*(n+1)
parts[-1] = 1
while q:
    a = q.popleft()
    for i, j in toy[a]:
        v[i] -= 1
        parts[i] += parts[a]*j
        if not v[i]:
            q.append(i)

for i in basic:
    print(i, parts[i])