import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n = int(input())
tree = [[]for _ in range(n+1)]

for _ in range(n-1):
    a, b = map(int, input().split())
    tree[a].append(b)
    tree[b].append(a)

def dfs(v):
    visited[v] = True
    for i in tree[v]:
        if not visited[i]:
            parent[i] = v
            dfs(i)
    


visited= [False]*(n+1)
parent = [-1]*(n+1)

dfs(1)

print(*parent[2:],sep='\n')
