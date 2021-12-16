# N = input()
# edifs = list(map(int, input().split(' ')))

N = '8'
edifs = list(map(int, '1 3 6 5 4 2 1 2'.split(' ')))
# N = '3'
# edifs = list(map(int, '2 7 2'.split(' ')))
# N = '4'
# edifs = list(map(int, '2 1 3 1'.split(' ')))
# N = '4'
# edifs = list(map(int, '2 2 3 1'.split(' ')))
N = '3'
edifs = list(map(int, '7 5 7'.split(' ')))  # 10

N = '1'
edifs = list(map(int, '2'.split(' ')))
# N = input()
# edifs = list(map(int, input().split(' ')))
area = 0
iReverse = len(edifs) - 1
jReverse = iReverse

for i in range(len(edifs)):
    j = i
    iReverse -= i

    area = max(area, edifs[i])

    while j < len(edifs) and edifs[j] >= edifs[i]:
        area = max(area, edifs[i] * (j - i + 1))
        j += 1

    jReverse = iReverse
    while jReverse >= 0 and edifs[jReverse] >= edifs[iReverse]:
        area = max(area, edifs[iReverse] * (iReverse - jReverse + 1))
        jReverse -= 1

    area = max(area, min(edifs) * len(edifs))
print(area)
