import sys
input = sys.stdin.readline

n = int(input())
ropes = []

for i in range(n):
    ropes.append(int(input()))

ropes.sort()

sum = []
sum.append(ropes[-1])

for i in range(1,n):
    sum.append(ropes[n-i-1]*(i+1))
    
print(max(sum))


