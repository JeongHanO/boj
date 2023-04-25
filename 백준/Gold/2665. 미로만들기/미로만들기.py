import sys
import heapq
input = sys.stdin.readline

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]


def bfs():
    hq = []
    heapq.heappush(hq, (0, 0, 0))
    visited[0][0] = 0
    while hq:
        cost, x, y = heapq.heappop(hq)
        if x == n-1 and y == n-1:
            print(cost)
            return
        for i in range(4):
            nx = x+dx[i]
            ny = y+dy[i]
            if 0 <= nx < n and 0 <= ny < n and visited[nx][ny] > cost+1:
                if maze[nx][ny] == 0:
                    visited[nx][ny] = min(visited[nx][ny], cost+1)
                else:
                    visited[nx][ny] = min(visited[nx][ny], cost)
                heapq.heappush(hq, (visited[nx][ny], nx, ny))


n = int(input())
maze = [list(map(int, input().strip())) for _ in range(n)]

visited = [[sys.maxsize]*n for _ in range(n)]
bfs()
