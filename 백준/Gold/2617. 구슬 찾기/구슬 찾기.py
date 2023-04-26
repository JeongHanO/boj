import sys
sys.stdin.readline


def dfs(arr, n):
    global cnt
    for i in arr[n]:
        if not visited[i]:
            visited[i] = True
            cnt += 1
            dfs(arr, i)


n, m = map(int, input().split())
minLst = [[]for _ in range(n+1)]
maxLst = [[]for _ in range(n+1)]
mid = (n+1)//2

for _ in range(m):
    a, b = map(int, input().split())
    maxLst[a].append(b)
    minLst[b].append(a)

ans = 0

for i in range(1, n+1):
    visited = [False]*(n+1)
    cnt = 0
    dfs(maxLst, i)
    if cnt >= mid:
        ans += 1
    cnt = 0
    dfs(minLst, i)
    if cnt >= mid:
        ans += 1

print(ans)