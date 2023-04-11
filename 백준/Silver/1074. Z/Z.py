N, R, C = map(int, input().split())
sum = 0


def div(n):
    return 2**(n-1)


def quad(r, c, n):
    line = 2**(n-1)-1
    if (r <= line and c <= line):  # 0
        return 0
    elif (r <= line and c > line):  # 1
        return 1
    elif (r > line and c <= line):  # 2
        return 2
    else:  # 3
        return 3


def search(r, c, n):
    global sum

    if n == 1:
        #print("r: ", r, "  c : ", c)
        #print("ddd: ", (r-1)*2+(c-1)*1)
        return r*2+c#-1*1
    

    whereQuad = quad(r, c, n)
    #print("whereQuad: ", quad(r, c, n))
    #print("qud: ", whereQuad*(2**(2*n-2)))
    #print("divN : ",n,div(n))
    if whereQuad == 0:  # r,c 값 뺄 필요 없음
        sum += whereQuad*(2**(2*n-2)) + search(r, c, n-1)
    elif whereQuad == 1:  # r 유지, c는 -
        sum += whereQuad*(2**(2*n-2)) + search(r, c-div(n), n-1)
    elif whereQuad == 2:  # r은 -, c는 유지
        sum += whereQuad*(2**(2*n-2)) + search(r-div(n), c, n-1)
    else:  # r,c -
        sum += whereQuad*(2**(2*n-2)) + search(r-div(n), c-div(n), n-1)

    return sum

if R ==0 and C == 0:
    print(0)
    exit()

sum += search(R, C, N)
print(sum)
