import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline


def dfs(dep, tmp):
    global add, minus, times, devide
    if dep == n:
        ans.append(tmp)
        return
    for i in range(4):
        if not opr[i]:
            continue
        if i == 0:
            opr[i] -= 1
            dfs(dep+1, tmp+a[dep])
            opr[i] += 1
        if i == 1:
            opr[i] -= 1
            dfs(dep+1, tmp-a[dep])
            opr[i] += 1
        if i == 2:
            opr[i] -= 1
            dfs(dep+1, tmp*a[dep])
            opr[i] += 1
        if i == 3:
            opr[i] -= 1
            if tmp < 0:
                tmp = -(abs(tmp)//a[dep])
            else:
                tmp = tmp//a[dep]
            dfs(dep+1, tmp)
            opr[i] += 1


n = int(input())
a = list(map(int, input().split()))
opr = list(map(int, input().split()))

ans = []
dfs(1, a[0])
ans.sort()
print(ans[-1])
print(ans[0])
