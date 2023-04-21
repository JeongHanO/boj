n = int(input())
lst = [list(input().split()) for _ in range(n)]

def preorder(node):
    print(node[0], end='')
    for i in lst:
        if node[1] == i[0]:
            preorder(i)
    for i in lst:
        if node[2] == i[0]:
            preorder(i)


def inorder(node):
    if node[1] == '.' and node[2] == '.':
        print(node[0], end='')
        return
    for i in lst:
        if node[1] == i[0]:
            inorder(i)
    print(node[0], end='')
    for i in lst:
        if node[2] == i[0]:
            inorder(i)


def postorder(node):
    if node[1] == '.' and node[2] == '.':
        print(node[0], end='')
        return
    for i in lst:
        if node[1] == i[0]:
            postorder(i)
    
    for i in lst:
        if node[2] == i[0]:
            postorder(i)
    print(node[0], end='')


preorder(lst[0])
print()
inorder(lst[0])
print()
postorder(lst[0])
