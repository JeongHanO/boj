n, k = map(int, input().split())

a = list(input().rstrip())
stack = []
length = k

for i in range(n):
    while k > 0 and stack and stack[-1] < a[i]:
        stack.pop()
        k -= 1
    stack.append(a[i])
print(''.join(stack[:len(stack)-k]))
