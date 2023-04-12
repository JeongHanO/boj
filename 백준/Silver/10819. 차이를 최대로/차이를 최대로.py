n = int(input())
arr = list(map(int,input().split()))

ans= 0
used = [0]*n
lst = []

def clac(arr): # 수식 계산
    tmp = 0
    for i in range(0,n-1):
        tmp += abs(arr[i]-arr[i+1])
    return tmp

def search(lst,used):
    global ans
    if len(lst) == n: #모든 경우의 수 탐색
        ans = max(ans,clac(lst)) #저장된 값과 계산된 값 중 큰 수 선택
        return
    
    for j in range(len(arr)):
        if not used[j]:
            lst.append(arr[j])
            used[j] = 1
            search(lst,used)
            used[j] = 0
            lst.pop() #고른 리스트의 마지막 값 삭제
        

search(lst,used)
print(ans)