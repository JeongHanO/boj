# class Node:
#     def __init__(self, value):
#         self.data = value
#         self.left = None
#         self.right = None


# class BTree():
#     def __init__(self):
#         self.root = None


n = int(input())
lst = [list(input().split()) for _ in range(n)]

# 배열로 푸는 방법은 없을까...
# 루트부터 시작해서 자식 노드로 들어감. 더이상 자식 노드가 없으면 리프노드로 판단, 거기에서 탐색 시작
# 재귀를 통해서 들어오면 return을 통해서 올라가면 됨.


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
