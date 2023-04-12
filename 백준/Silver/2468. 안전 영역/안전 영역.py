import sys
sys.setrecursionlimit(10**6)
n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]

ans = 0

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]


def safe(x, y, height, visited):
    # print(x, y)
    visited[x][y] = 1
    nx = [x+dx[0], x+dx[1], x+dx[2], x+dx[3]]
    ny = [y+dy[0], y+dy[1], y+dy[2], y+dy[3]]
    # if(x+1<n and y+1 < n and arr[x+1][y+1]>h and visited[x+1][y+1] == 0):
    #   safe(x+1,y+1)
    for i in range(4):
        if 0 <= nx[i] < n and 0 <= ny[i] < n and arr[nx[i]][ny[i]] > height and visited[nx[i]][ny[i]] == 0:
            visited[nx[i]][ny[i]] = 1
            safe(nx[i], ny[i], height, visited)


res = 0
for h in range(0, 101):
    cnt = 0
    visited = [[0 for _ in range(n)]for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if arr[i][j] > h and visited[i][j] == 0:
                cnt += 1
                # print(f'({i} {j})  {cnt}')
                visited[i][j] = 1
                safe(i, j, h, visited)
    if res < cnt:
        res = cnt

print(res)
