import sys

n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]

ans = sys.maxsize


def travel(start, now, cost, visited):
    global ans
    if len(visited) == n:  # 모든 마을을 전부 방문하면
        if arr[now][start] != 0:
            ans = min(ans, cost+arr[now][start])  # 출발 지점으로 돌아오는 비용
        return

    for i in range(n):
        if i not in visited and arr[now][i] != 0 and i != start:  # 마을에 방문한 기록이 없으면
            visited.append(i)
            travel(start, i, cost + arr[now][i], visited)
            visited.pop()


for i in range(n):
    travel(i, i, 0, [i])

print(ans)
