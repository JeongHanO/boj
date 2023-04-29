a = ' ' + input()
b = ' ' + input()
arr = [[0]*(len(b)+1) for _ in range(len(a)+1)]

for i in range(1, len(a)):
    for j in range(1, len(b)):
        if a[i] == b[j]:
            arr[i][j] = arr[i-1][j-1]+1
        else:
            arr[i][j] = max(arr[i-1][j], arr[i][j-1])

print(max(max(arr)))
