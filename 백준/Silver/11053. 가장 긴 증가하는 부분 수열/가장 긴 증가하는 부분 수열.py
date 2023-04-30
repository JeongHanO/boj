n = int(input())
lst = list(map(int, input().split()))

arr = [1]*n

for i in range(1,n):
    for j in range(i):
        if lst[i] > lst[j]:
            arr[i] = max(arr[i], arr[j]+1)

print(max(arr))
