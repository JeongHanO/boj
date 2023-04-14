import sys

k = int(sys.stdin.readline())
lst = []

for _ in range(k):
    ord = int(sys.stdin.readline())
    if not ord:
        if len(lst) == 0:
            continue
        else:
            lst.pop()
    else:
        lst.append(int(ord))
        
print(sum(lst))