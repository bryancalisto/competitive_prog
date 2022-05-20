N = int(input())

tree = {}

for i in range(N - 1):
    treeData = input().split(' ')
    tree['0'] = None
    tree[treeData[1]] = treeData[0]  # key=child, value=parent

# print(tree)
# exit()
C = int(input())

for i in range(C):
    wasYes = False
    query = input().split(' ')
    ancestor = query[0]
    child = query[1]

    if ancestor == '0' or ancestor == child:
        print('Yes')
        continue

    parent = tree[child]

    while parent is not None:
        if parent == ancestor:
            print('Yes')
            wasYes = True
            break

        parent = tree[parent]

    if not wasYes:
        print('No')
