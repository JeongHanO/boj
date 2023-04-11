arr = [int(input()) for _ in range(9)]
lst = []



def search(i,dep):
    if dep == 7:
        if sum(lst) == 100:
            lst.sort()
            for x in range(7):
                print(lst[x])
            exit()
        else:
            return

    for j in range(i,9):
        lst.append(arr[j])
        search(i+1,dep+1)
        lst.pop()


search(0,0)