n = int(input())
lst = list(map(int, input().split()))

lst.sort()
# abs(절댓값)의 값을 이용하여 0과 제일 가까운 수 추리기
# 양수이면 pr을 줄이고 음수이면 pl을 늘림

pl = 0
pr = n-1
sum = abs(lst[0] + lst[-1])
ans = [lst[0],lst[-1]]

while pl < pr:
    lv = lst[pl]
    rv = lst[pr]
    tmp = lv + rv

    if abs(tmp) < sum:
        sum = abs(tmp)
        ans = [lv,rv]
        if tmp == 0:
            break
    if tmp < 0:
        pl += 1
    else:
        pr -= 1


print(*ans)