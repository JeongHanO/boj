import sys

k = int(sys.stdin.readline())
lst = []

for _ in range(k):
    ord = int(sys.stdin.readline())
    if ord != 0:
        lst.append(int(ord))
    else:
        if len(lst) == 0:
            continue
        else:
            lst.pop()
    


print(sum(lst))