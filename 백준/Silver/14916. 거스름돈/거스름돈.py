n = int(input())

if n == 1 or n == 3:
    print(-1)
    quit()

five = n//5
two = n%5//2
if n % 5 == 1 or n % 5 == 3:
    five -= 1
    two = (n%5+5)//2


print(five+two)
