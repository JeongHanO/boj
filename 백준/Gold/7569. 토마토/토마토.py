import sys
import copy
from collections import deque
input = sys.stdin.readline


def check():
    for k in range(h):
        for i in range(n):
            for j in range(m):
                if not box[k][i][j]:
                    return False
    return True


def bfs():
    global days
    q = deque()
    tmp_q = deque()
    dx = [1, -1, 0, 0, 0, 0]
    dy = [0, 0, 1, -1, 0, 0]
    dz = [0, 0, 0, 0, 1, -1]
    for k in range(h):
        for i in range(n):
            for j in range(m):
                if box[k][i][j] == 1:
                    q.append([i, j,k])
    while q:
        d = False
        for _ in range(len(q)):
            x, y, z = q.popleft()
            for i in range(6):
                nx = x + dx[i]
                ny = y + dy[i]
                nz = z + dz[i]
                if 0 <= nx < n and 0 <= ny < m and 0 <= nz < h and box[nz][nx][ny] == 0:
                    tmp_q.append([nx, ny, nz])
                    box[nz][nx][ny] = 1
                    d = True
        if d:
            days += 1

        q = copy.deepcopy(tmp_q)
        tmp_q.clear()
    if not check():
        print(-1)
        return
    print(days)


m, n, h = map(int, input().split())
box = [[list(map(int, input().split()))for _ in range(n)]for _ in range(h)]
days = 0


bfs()
