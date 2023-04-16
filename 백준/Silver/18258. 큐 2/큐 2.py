import sys
from collections import deque

n = int(input())
dq = deque()
for _ in range(n):
    order = list(sys.stdin.readline().split())
    if order[0] == "push":
        dq.append(int(order[1]))
    elif order[0] == 'pop':
        if dq:
            print(dq.popleft())
        else:
            print(-1)
    elif order[0] == 'size':
        print(len(dq))
    elif order[0] == 'empty':
        if dq:
            print(0)
        else:
            print(1)
    elif order[0] == 'front':
        if dq:
            print(dq[0])
        else:
            print(-1)
    elif order[0] == 'back':
        if dq:
            print(dq[-1])
        else:
            print(-1)
