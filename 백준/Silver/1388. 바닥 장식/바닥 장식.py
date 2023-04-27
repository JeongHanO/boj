import sys
from collections import deque
input = sys.stdin.readline

dx = [1, -1]
dy = [1, -1]


def bfs(a, b):
    visited[a][b] = True
    q = deque()
    q.append((a, b))
    if floor[a][b] == '-':
        while q:
            x, y = q.popleft()
            for i in range(2):
                ny = y + dy[i]
                if 0 <= ny < m and not visited[x][ny] and floor[x][ny] == '-':
                    q.append((x, ny))
                    visited[x][ny] = True

    else:
        while q:
            x, y = q.popleft()
            for i in range(2):
                nx = x + dx[i]
                if 0 <= nx < n and not visited[nx][y] and floor[nx][y] == '|':
                    q.append((nx, y))
                    visited[nx][y] = True
    return 1


# - 가 나오면 visited 확인해서 가로로, |가 나오면 세로로
n, m = map(int, input().split())
floor = [list(input().strip()) for _ in range(n)]
visited = [[False]*m for _ in range(n)]
cnt = 0

for i in range(n):
    for j in range(m):
        if not visited[i][j]:
            cnt += bfs(i, j)

print(cnt)
