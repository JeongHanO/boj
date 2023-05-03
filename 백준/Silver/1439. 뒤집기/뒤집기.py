n = input()
zero = 0
one = 0

if int(n[0]):
    one += 1
    
else:
    zero += 1


for i in range(1, len(n)):
    if n[i] != n[i-1]:
        if int(n[i]):
            one += 1
        else:
            zero += 1

print(min(one, zero))
