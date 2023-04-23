import sys
from collections import deque
input = sys.stdin.readline


def bfs(v):
    visited[v] = True
    q = deque()
    q.append(v)
    while q:
        a = q.popleft()
        for i in lst[a]:
            if not visited[i]:
                q.append(i)
                visited[i] = True
                dist[i] = dist[a] + 1


n, m, k, x = map(int, input().split())
lst = [[] for _ in range(n+1)]

for _ in range(m):
    a, b = map(int, input().split())
    lst[a].append(b)

visited = [False]*(n+1)
dist = [0]*(n+1)
bfs(x)

ans = []

for i in range(len(dist)):
    if dist[i] == k:
        ans.append(i)

ans.sort()

if ans:
    print(*ans, sep='\n')
else:
    print(-1)
