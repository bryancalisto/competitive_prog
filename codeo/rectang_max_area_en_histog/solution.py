N = 8
edifs = list(map(int, '1 3 6 5 4 2 1 2'.split(' ')))
# N = 3
# edifs = list(map(int, '2 7 2'.split(' ')))
# N = '4'
# edifs = list(map(int, '2 1 3 1'.split(' ')))
# N = '4'
# edifs = list(map(int, '2 2 3 1'.split(' ')))
# N = '3'
# edifs = list(map(int, '7 5 7'.split(' ')))  # 10

# N = int(input())
# edifs = list(map(int, input().split(' ')))
area = 0

for i in range(N):
    area = max(area, edifs[i])
    localMin = 100000
    for j in range(i + 1, N):
        localMin = min(localMin, edifs[j])
        newArea = min(localMin, min(edifs[i], edifs[j])) * ((j-i)+1)
        area = max(area, newArea)

print(area)
