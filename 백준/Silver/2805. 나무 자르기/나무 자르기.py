import sys
n, m = map(int, sys.stdin.readline().split())
lst = list(map(int, sys.stdin.readline().split()))

pl = 1
pr = max(lst)

while pl <= pr:
    pc = (pl + pr)//2
    sum = 0
    for i in lst:
        if i > pc:
            sum += (i-pc)
    #print(f'1111 : pl = {pl} / pr = {pr} / pc = {pc} / sum = {sum}')
    if sum >= m:
        pl = pc + 1
    else:
        pr = pc - 1
    #print(f'2222 : pl = {pl} / pr = {pr} / pc = {pc} / sum = {sum}')

print(pr)
