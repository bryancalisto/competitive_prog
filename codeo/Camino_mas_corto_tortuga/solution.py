# N, X, Y = list(map(lambda x: int(x), input().split(' ')))
# print(min((Y-X) % N, (N-Y+X) % N))
# print(min(abs(Y-X) % N, abs(N-Y+X) % N))


def minMovs(N, X, Y):
    # N, X, Y = list(map(lambda x: int(x), input().split(' ')))
    # print(abs(N-max(Y, X) + min(Y, X)) % N)
    print(min((Y-X) % N, (N-Y+X) % N))
    # print(min(abs(Y-X) % N, abs(N-max(Y, X) + min(Y, X))))


minMovs(7, 2, 6)  # 3
minMovs(7, 3, 4)  # 1
minMovs(7, 6, 0)  # 1
minMovs(10, 9, 0)  # 1
minMovs(49937, 39133, 23279)  # 15854
