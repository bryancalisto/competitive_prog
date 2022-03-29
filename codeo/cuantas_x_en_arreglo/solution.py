N = input()
arr = input().split(' ')
times = int(input())
mem = {}

for i in range(times):
    case = input().split(' ')
    l = int(case[0])
    r = int(case[1])
    q = case[2]
    count = 0

    for j in range(l, r + 1):
        if arr[j] == q:
            count += 1

    print(count)
