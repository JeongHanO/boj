import sys
import heapq
input = sys.stdin.readline

v, e = map(int, input().split())
visited = [False]*(v+1)
adj = [[]for _ in range(v+1)]
heap = [[0, 1]]  # 가중치가 0인 첫 번째 노드를 방문하기 위함

for _ in range(e):
    a, b, c = map(int, input().split())
    adj[a].append([c, b])
    adj[b].append([c, a])

ans = 0
cnt = 0

while heap:
    if cnt == v:
        break
    w, s = heapq.heappop(heap)
    if not visited[s]:
        visited[s] = True
        ans += w
        cnt += 1
        for i in adj[s]:
            heapq.heappush(heap, i) 
# 한 노드에서 연결된 모든 노드를 heap에 넣음
# visited 배열과 heap의 특성을 이용해서, 가중치가 가장 작은 경로를 선택하고 노드 방문을 체크해서 그 외의 경로를 선택에서 제외함

print(ans)
