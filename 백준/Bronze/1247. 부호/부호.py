import sys
input = sys.stdin.readline

for _ in range(3):
    n = int(input())
    _sum = 0

    for _ in range(n):
        _sum += int(input())

    if _sum == 0:
        print(0)
    elif _sum < 0:
        print("-")
    else:
        print("+")