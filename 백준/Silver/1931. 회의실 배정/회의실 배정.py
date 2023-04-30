import sys
input = sys.stdin.readline

n = int(input())
meeting=[]
for _ in range(n):
    meeting.append(list(map(int,input().split())))

meeting.sort()
meeting.sort(key=lambda x: x[1])

ans = 0
tmp = [0,0]
for i in range(n):
    if meeting[i][0] >= tmp[1]:
        tmp = meeting[i]
        ans += 1

print(ans)

