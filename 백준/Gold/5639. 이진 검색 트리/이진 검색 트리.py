import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

lst = []

while True:
    try:
        n = input()
        lst.append(int(n))
    except:
        break


def pre_to_post(l, r):
    if l > r:
        return
    root = lst[l]
    idx = None
    for i,v in enumerate(lst[l+1:],l+1):
        if v > root:
            idx = i
            break
    if idx is None:
        idx = r + 1
    pre_to_post(l+1,idx-1)
    pre_to_post(idx,r)
    print(root)

pre_to_post(0,len(lst)-1)