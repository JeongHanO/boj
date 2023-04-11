import sys

n = int(input())
lst = [0]*10000

for i in range(n):
    a = int(sys.stdin.readline())
    lst[a-1] += 1

# lst1 = sorted(list)
for i in range(10000):
    if lst [i] != 0:
        for _ in range(lst[i]):
            print(i+1)
