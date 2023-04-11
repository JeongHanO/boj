n = int(input())
row = [0]*n
cnt = 0

def rec(x):
    global cnt
    if x == n:
        cnt += 1
    else:
        for y in range(n):
            row[x] = y
            if check(x):
                rec(x+1)

def check(x):
    for i in range(x):
        if (row[x] == row[i]) or (abs(row[i]-row[x])==(x-i)):
            return False
    return True

rec(0)
print(cnt)