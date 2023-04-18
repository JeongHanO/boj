def color(paper, x, y, n):
    cnt = 0
    for i in range(n):
        for j in range(n):
            if paper[x+i][y+j] == 1:
                cnt += 1
    if cnt == n**2:
        return 1
    elif cnt == 0:
        return 2
    else:
        return 0

# 왼쪽 상단의 좌표와 크기를 넘겨주는 함수로 만들기
# 왼쪽 상단의 좌표는 mid값을 이용해서 넘겨주고 크기는 n/2로 넘겨주면 될듯


def cut(paper, x, y, n):
    global blue, white
    bw = color(paper, x, y, n)

    if bw == 1:
        blue += 1
        return
    elif bw == 2:
        white += 1
        return
    else:
        mid = n//2
        cut(paper, x, y, mid)
        cut(paper, x+mid, y, mid)
        cut(paper, x, y+mid, mid)
        cut(paper, x+mid, y+mid, mid)


n = int(input())
paper = [list(map(int, input().split())) for _ in range(n)]

blue = 0
white = 0

cut(paper, 0, 0, n)
print(white)
print(blue)
