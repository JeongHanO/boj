n = int(input())
a, b = map(int, input().split())
c = int(input())
d = []

for _ in range(n):
    d.append(int(input()))

d.sort(reverse=True)

toping_cnt = 0
total_cal = c

per_cal = c//a
for i in d:
    per_cal = (total_cal)/(toping_cnt*b+a)
    if (total_cal+i)/((toping_cnt+1)*b+a) >per_cal:
        total_cal += i
        toping_cnt += 1
    else:
        break
per_cal = (total_cal)/(toping_cnt*b+a)
print(int(per_cal))