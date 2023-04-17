import sys
n, c = map(int, input().split())
lst = []
for _ in range(n):
    lst.append(int(sys.stdin.readline()))
lst.sort()

start = 1
end = lst[-1] - lst[0]
ans = 0

while start <= end:
    mid = (start + end) // 2
    cnt = 1
    tmp = lst[0]

    for i in range(1,len(lst)):
        if lst[i] >= tmp + mid:
            cnt += 1
            tmp = lst[i]    
    if cnt >= c:
        start = mid + 1
        ans = mid
    else:
        end = mid - 1

print(ans)