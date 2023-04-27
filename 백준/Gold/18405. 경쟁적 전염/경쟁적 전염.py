import sys
from collections import deque
input = sys.stdin.readline

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]


# 계속 갱신하면 안되고 새로운 지도를 그리거나 좌표를 기록. q가 비었을 때 갱신해야 될듯.

def bfs(a, b, v):
    extend_vir = []
    visited[a][b] = True
    q = deque()
    q.append((a, b))
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < n and not visited[nx][ny] and not vir[nx][ny]:
                visited[nx][ny] = True
                extend_vir.append((nx, ny))
            elif 0 <= nx < n and 0 <= ny < n and not visited[nx][ny] and vir[nx][ny] == v:
                visited[nx][ny] = True
                q.append((nx, ny))
    return extend_vir


def check():
    for i in range(n):
        for j in range(n):
            if not vir[i][j]:
                return True
    return False

n, k = map(int, input().split())
vir = [list(map(int, input().split()))for _ in range(n)]
s, xx, yy = map(int, input().split())
ans_x = xx - 1
ans_y = yy - 1

# 바이러스의 번호가 작은 것의 위치부터 bfs를 하면서 '한 칸만' 확장하고 넘어가야함.
# 모든 바이러스를 순회하면 sec += 1

sec = 0
visited = [[False]*n for _ in range(n)]

while sec < s:
    if not check():  # 모든 칸에 바이러스가 펴졌을 경우, 반복문 종료
        break
    tmp_vir = []
    for i in range(n):
        for j in range(n):
            if vir[i][j]:  # 모든 칸을 돌면서 바이러스가 있으면 tmp_vir에 바이러스 번호, x좌표, y좌표를 기록함.
                tmp_vir.append([vir[i][j], i, j])
    tmp_vir.sort()  # tmp_vir에 있는 바이러스들을 순서대로 정리
    # for i in tmp_vir:
    #     vir_info.append(i)
    vir_info = deque(tmp_vir)  # tmp_vir을 deque에 넣음
    for i in range(len(vir_info)):
        key = vir_info.popleft()  # 큐의 앞에 있는 값을 꺼냄.
        for j in bfs(key[1], key[2], key[0]):
            a = j[0]
            b = j[1]
            vir[a][b] = key[0]
    sec += 1

print(vir[ans_x][ans_y])

