import sys
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().split())
student = [[]for _ in range(n+1)]
v = [0]*(n+1)
for _ in range(m):
    a, b = map(int, input().split())
    student[a].append(b)
    v[b] += 1

q = deque()
for i in range(1,n+1):
    if v[i] == 0:
        q.append((i))

ans = []

while q:
    a = q.popleft()
    ans.append(a)
    for i in student[a]:
        v[i] -= 1
        if not v[i]:
            q.append(i)

print(*ans,sep=' ')