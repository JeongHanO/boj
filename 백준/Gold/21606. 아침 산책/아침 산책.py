import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline


def dfs(v):
    global cnt
    visited[v] = True
    for i in graph[v]:
        if not visited[i]:
            if out[i] == '1':
                #print('1i = ',i)
                cnt += 1
                visited[i] = True
                continue
            else:
                #print('0일때 i : ',i)
                dfs(i)

n = int(input())
out = '2'
out += input()

graph = [[]for _ in range(n+1)]

for _ in range(n-1):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)


cnt = 0
for i in range(1,len(out)):
    if out[i] == '1':
        #print("i번째 for문: ",i)
        #print(graph)
        visited = [False]*(n+1)
        dfs(i)

print(cnt)
