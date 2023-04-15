lst = list(input())
stack = []
sum = 0
tmp_sum = 1

for i in range(len(lst)):
    if lst[i] == '(':
        stack.append('(')
        tmp_sum *= 2
    elif lst[i] == '[':
        stack.append('[')
        tmp_sum *= 3

    elif lst[i] == ')':
        if not stack or stack[-1] == '[':
            sum = 0
            break
        if lst[i-1] == '(':
            sum += tmp_sum
        tmp_sum //= 2
        stack.pop()

    elif lst[i] == ']':
        if not stack or stack[-1] == '(':
            sum = 0
            break
        if lst[i-1] == '[':
            sum += tmp_sum
        tmp_sum //= 3
        stack.pop()

if stack:
    sum = 0
print(int(sum))
