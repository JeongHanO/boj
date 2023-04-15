n = int(input())

for _ in range(n):
    a = input()
    lst = []
    vps = True
    for i in a:
        if i == ')':
            if not lst:
                vps = False
                break
            else:
                lst.pop()
        else:
            lst.append('(')
    if not lst and vps:
        print('YES')
    else:
        print('NO')
