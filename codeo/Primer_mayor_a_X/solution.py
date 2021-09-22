def findIndex(arr, num, l, m, r, mem={}):
    if num in mem:
        return mem[num]

    if l >= r:
        mem[num] = m + 1
        return m + 1

    if arr[m] <= num:
        l = m+1
        return findIndex(arr, num, l, (l + r) // 2, r, mem)
    else:
        r = m
        return findIndex(arr, num, l, (l + r) // 2, r, mem)


N = int(input())
arr = list(map(lambda x: int(x), input().split(' ')))
c = int(input())

for i in range(c):
    consulta = int(input())
    print(findIndex(arr, consulta, 0, (len(arr)-1)//2, len(arr))-1)

# TEST
arr = [1, 2, 4, 7, 7, 10]
c = 1
print(findIndex(arr, 4, 0, (len(arr)-1)//2, len(arr))-1)
print(findIndex(arr, 5, 0, (len(arr)-1)//2, len(arr))-1)
print(findIndex(arr, -1, 0, (len(arr)-1)//2, len(arr))-1)
print(findIndex(arr, 100, 0, (len(arr)-1)//2, len(arr))-1)
print(findIndex(arr, 7, 0, (len(arr)-1)//2, len(arr))-1)
