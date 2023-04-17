n = int(input())
lst = list(map(int, input().split()))

dp = [1]*n

for i in range(n):
    for j in range(i):
        if lst[i]>lst[j]: #새로운 값이 기존 값보다 크면
            dp[i] = max(dp[i],dp[j]+1) #기존 값이 가진 최대 부분 수열의 길이와 비교해서 갱신

#dp라는 lst와 길이가 같은 배열을 만들어서, lst와 같은 인덱스에 부분 수열의 길이를 기록한다.

print(max(dp))