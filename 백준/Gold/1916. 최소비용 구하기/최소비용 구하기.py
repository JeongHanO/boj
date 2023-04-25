import sys
import heapq
input = sys.stdin.readline


def dfs(v):
    visited[v] = 0
    q = [(0, start)]

    while q:
        tmp_visited, position = heapq.heappop(q)
        if visited[position] < tmp_visited:
            continue

        for dest, cost in bus[position]:
            tmp_cost = visited[position]+cost
            if tmp_cost < visited[dest]:
                visited[dest] = tmp_cost
                heapq.heappush(q, (tmp_cost, dest))


n = int(input())
m = int(input())

bus = [[]for _ in range(n+1)]

for _ in range(m):
    a, b, c = map(int, input().split())
    bus[a].append((b, c))
start, end = map(int, input().split())
visited = [sys.maxsize]*(n+1)

dfs(start)
print(visited[end])
