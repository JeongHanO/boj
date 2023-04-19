import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
k = int(input())
apple = []

for _ in range(k):
    apple.append(list(map(int, input().split())))

l = int(input())

move = deque()
for _ in range(l):
    move.append(list(input().split()))

dxy = ((0, 1), (1, 0), (0, -1), (-1, 0))
dir = 0
way = dxy[dir]

second = 0

snake = deque()
snake.append([1, 1])

while True:
    # 시간 증가
    second += 1

    # 덱의 앞에서 push하고 뒤에서 Pop하는 방식으로 진행
    # 머리 위치를 바꾸지 말고 진행 방향에 있는 블럭을 추가해줌

    # 머리 이동
    movingX = snake[0][0]
    movingY = snake[0][1]
    movingX += way[0]
    movingY += way[1]
    snake.appendleft((movingX, movingY))
    
    # print(f'moving = {moving[0]} | moving = {moving[1]}')
    # 맵 영역 밖
    if movingX < 1 or movingX > n or movingY < 1 or movingY > n:
        print(second)
        quit()

    # 머리, 몸통 만남
    for i in range(1, len(snake)):
        if snake[0][0] == snake[i][0] and snake[0][1] == snake[i][1]:
            print(second)
            quit()
    tail = snake.pop()  # 꼬리 이동
    # 사과 먹음
    for i in range(len(apple)):
        if apple and movingX == apple[i][0] and movingY == apple[i][1]:
            del apple[i]
            snake.append(tail)
            break

    # 시간에 따른 방향 확인
    if move and second == int(move[0][0]):
        if move[0][1] == 'D':
            dir = (dir + 1) % 4
        else:
            dir = (dir + 3) % 4
        way = dxy[dir]
        move.popleft()
    #print(f'second = {second} | {snake}')
    # 위치 확인용
    # print(f'second = {second} / moving = {moving} / snake = {snake}')
