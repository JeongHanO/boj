from collections import deque

n, m, v = map(int, input().split())

lst = [[] for _ in range(n+1)]

for _ in range(m):
    a, b = map(int, input().split())
    lst[a].append(b)
    lst[b].append(a)

for i in range(1, n+1):
    lst[i].sort()


def dfs(v):
    visited[v] = True
    print(v, end=' ')
    for i in lst[v]:
        if not visited[i]:
            dfs(i)
    return


def bfs(v):
    visited[v] = True
    q = deque()
    q.append(v)
    while q:
        a = q.popleft()
        print(a,end=' ')
        for i in lst[a]:
            if not visited[i]:
                q.append(i)
                visited[i] = True
    return


visited = [False]*(n+1)
dfs(v)
print()
visited = [False]*(n+1)
bfs(v)
print()
