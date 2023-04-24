import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline


def dfs(v, c):
    global bg
    if not bg:
        return
    color[v] = c
    for i in lst[v]:
        if color[i] == -1:
            if c == 1:
                dfs(i, 2)
            elif c == 2:
                dfs(i, 1)
        else:
            if color[v] == color[i]:
                bg = False
                return


k = int(input())
ans = []

for _ in range(k):
    v, e = map(int, input().split())
    color = [-1]*(v+1)  # -1= 방문 안함 / 1, 2 = 색칠
    lst = [[]for _ in range(v+1)]
    bg = True
    for _ in range(e):
        a, b = map(int, input().split())
        lst[a].append(b)
        lst[b].append(a)
    for i in range(1,v+1):
        if color[i] == -1:
            dfs(i,1)
    if not bg:
        ans.append('NO')
    else:
        ans.append('YES')

print(*ans, sep='\n')
