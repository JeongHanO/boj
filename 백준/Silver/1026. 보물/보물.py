n = int(input())
arr_a = list(map(int, input().split()))
arr_b = list(map(int, input().split()))

arr_a.sort()
arr_b.sort()

ans =[]


for i in range(n):
    ans.append(arr_a[n-i-1]*arr_b[i])

print(sum(ans))
