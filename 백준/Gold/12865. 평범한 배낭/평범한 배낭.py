n,k = map(int,input().split())
stuff = [list(map(int,input().split())) for _ in range(n)]

arr = [[0]*(k+1)for _ in range(n+1)]

for j in range(1,n+1):
    for i in range(1,k+1):
        if i >= stuff[j-1][0]:
            arr[j][i] = max(arr[j-1][i],arr[j-1][i-stuff[j-1][0]]+stuff[j-1][1])
        else:
            arr[j][i] = arr[j-1][i]

print(arr[-1][-1])


