
def dfs(x, y):
    if x == m-1 and y == n-1:
        return 1
    if dp[x][y] != -1:
        return dp[x][y]

    cnt = 0
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < m and 0 <= ny < n and road[nx][ny] < road[x][y]:
            cnt += dfs(nx, ny)

    dp[x][y] = cnt
    return dp[x][y]


m, n = map(int, input().split())
road = [list(map(int, input().split()))for _ in range(m)]

dp = [[-1]*n for _ in range(m)]
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

print(dfs(0,0))