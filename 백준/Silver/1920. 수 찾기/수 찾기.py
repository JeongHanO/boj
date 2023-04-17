import sys


def search(a, left, right, lst):
    while True:
        mid = (left + right) // 2
        if a == lst[mid]:
            print(1)
            return
        elif a > lst[mid]:
            left = mid + 1
        elif a < lst[mid]:
            right = mid - 1
        if left > right:
            break
    print(0)
    return


n = int(input())
lst = list(map(int, input().split()))

lst.sort()

m = int(input())
arr = list(map(int, input().split()))
for i in arr:
    search(i, 0, n-1, lst)
