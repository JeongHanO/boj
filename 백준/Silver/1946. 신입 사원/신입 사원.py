import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t): 
    n = int(input())
    score = [list(map(int,input().split()))for _ in range(n)]
    score.sort()
    tmp = score[0][1]
    ans = 1
    for i in range(1,n):
        if score[i][1] < tmp:
            tmp = score[i][1]
            ans += 1
    print(ans)
    