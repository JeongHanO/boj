import re
from collections import deque

expression = input()
numbers = re.findall('\d+', expression) 
operators = re.findall('\D', expression)

lst = deque(numbers)
result = []
result.append(int(lst.popleft()))

for i in operators:
    if i == '+':
        result.append(int(result.pop())+int(lst.popleft()))
    else:
        result.append(int(lst.popleft()))
ans = result[0]
for i in range(1,len(result)):
    ans -= result[i]

print(ans)