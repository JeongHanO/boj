import sys

input = sys.stdin.readline


def check(gun, ani, l):
    if abs(gun-ani[0])+ani[1] <= l:
        
        return True
    return False


m, n, l = map(int, input().split())
gun = list(map(int, input().split()))
animal = [list(map(int, input().split())) for _ in range(n)]

gun.sort()

cnt = 0

for i in animal:
    pl = 0
    pr = m
    mid = 0
    #print(i)
    while pl <= pr:
        mid = (pl+pr)//2
        #print(gun[mid])
        #print(i)
        if check(gun[mid], i, l):
            # print(gun[mid])
            # print(i)
            cnt += 1
            break

        elif gun[mid] > i[0]:
            pr = mid - 1
        else:
            pl = mid + 1


print(cnt)

# 동물의 x좌표와 가장 가까운 사대를 찾아서
# 사정거리 안에 들어가는지 판단하기

