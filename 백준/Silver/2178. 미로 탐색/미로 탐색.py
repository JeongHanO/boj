import sys
from collections import deque
input = sys.stdin.readline

dir = [[1, 0], [-1, 0], [0, 1], [0, -1]]


def bfs(x, y, tmp):
    visited[x][y] = 1
    
    q = deque()
    q.append((x, y, tmp))
    while q:
        a, b, c = q.popleft()
        for i in range(4):
            dx = a+dir[i][0]
            dy = b+dir[i][1]
            if -1 < dx < n and -1 < dy < m and visited[dx][dy] < 0 and maze[dx][dy]:
                visited[dx][dy] = c+1
                # if dx == n-1 and dy == m-1:
                #     print(*visited,sep = '\n')
                q.append((dx, dy, c+1))


n, m = map(int, input().split())
maze = [list(map(int, input().strip())) for _ in range(n)]
visited = [[-1]*m for _ in range(n)]
ans = sys.maxsize
bfs(0, 0, 1)
print(visited[n-1][m-1])