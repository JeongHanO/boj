a, b = map(int, input().split())

cnt = 0
while a < b:
    if not b%2:
        b//=2
        cnt +=1
    elif b%10 == 1:
        b //= 10
        cnt +=1
    else:
        print(-1)
        quit()
if a == b:
    print(cnt+1)
else:
    print(-1)