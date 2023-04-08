xx,yy = map(int,input().split())

n = int(input())

x = [0]
y = [0]
ans = 0
for _ in range(n):
    a,b = map(int,input().split())
    
    if(a==1):
        x.append(b)
    else:
        y.append(b)
x.append(xx)
y.append(yy)
x.sort()
y.sort()

for i in range(1,len(x)):
    xl = x[i] - x[i-1]
    
    for j in range(1,len(y)):
        yl = y[j] - y[j-1]
        
        ans = max(ans,xl*yl)

print(ans)


