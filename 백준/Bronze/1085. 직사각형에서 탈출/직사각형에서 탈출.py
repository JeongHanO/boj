x,y,w,z = map(int,input().split())

dist = [x,y,w-x,z-y]
print(min(dist))