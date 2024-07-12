import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    N = int(input())
    lst = list(map(int ,input().split()))   # 0부터 N-1까지로 -1해줘야함.
    v = [False]*N

    ans = 0

    for i in range(N):
        if v[i]: continue   # 만약 이미 방문했다면 pass
        ans += 1

        n = lst[i]-1  # 다음 방문할 곳은 n
        while 1:   # 다시 나로 돌아올 때 까지
            if v[n]:
                break   # 이미 방문한 곳 = 사이클이 있는 곳
            else:
                v[n] = True
                n = lst[n]-1

    print(ans)