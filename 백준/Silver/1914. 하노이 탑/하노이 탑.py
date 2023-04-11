def move(st,de):
    print(st,de)

def hanoi(st,de,n):
    if(n==1):
        move(st,de)
        return

    hanoi(st,6-st-de,n-1)
    move(st,de)
    hanoi(6-st-de, de, n-1)


n = int(input())
print(2**n-1)
if n <= 20:
    hanoi(1,3,n)