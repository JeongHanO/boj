import sys
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().split())

adj = [[]for _ in range(n+1)]

for _ in range(m):
    a, b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)


def bfs(v):
    global cnt
    if visited[v]:
        return
    visited[v] = True
    q = deque()
    q.append(v)
    while q:
        a = q.popleft()
        for i in adj[a]:
            if not visited[i]:
                q.append(i)
                visited[i] = True
    cnt += 1


visited = [False]*(n+1)

cnt = 0
for i in range(1, n+1):
    bfs(i)

print(cnt)
