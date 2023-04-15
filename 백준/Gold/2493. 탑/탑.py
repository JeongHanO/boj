n = int(input())
top = list(map(int,input().split()))

stack = []
ans = []

for i in range(n):
    while stack:
        if stack[-1][1] > top[i]: #앞의 탑이 더 큰 경우
            ans.append(stack[-1][0]+1)
            break
        else:
            stack.pop()
    if not stack:
        ans.append(0)
    stack.append((i,top[i]))

print(*ans)