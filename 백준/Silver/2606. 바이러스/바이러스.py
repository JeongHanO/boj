from collections import deque
n = int(input())
m = int(input())

adj = [[]for _ in range(n+1)]

for _ in range(m):
    a, b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)


def dfs(v):
    global cnt
    visited[v] = True
    q = deque()
    q.append(v)
    while q:
        a = q.popleft()
        for i in adj[a]:
            if not visited[i]:
                q.append(i)
                cnt += 1
                visited[i] = True


cnt = 0
visited = [False]*(n+1)
dfs(1)
print(cnt)
