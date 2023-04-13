n = input()

if int(n) < 10:
    n = '0' + n

cycle = 0
tmp = n

while True:
    new = int(tmp[0])+int(tmp[1])
    new = str(new)
    tmp = tmp[1] + new[len(new)-1]

    cycle += 1
    if tmp == n:
        print(cycle)
        break
