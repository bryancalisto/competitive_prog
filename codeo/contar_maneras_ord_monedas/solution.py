# 1000000007

N = int(input())
monedas = list(map(int, input().split(' ')))
M = int(input())


for i in range(M):
    cantidad = int(input())

    tbl = [0] * (cantidad + 1)  # cada espacio representa una cantidad de monedas hasta la cantidad que buscamos, que es la ultima
    tbl[0] = 1  # si hay 0 monedas, hay 1 forma de distribuirlas: 0

    for i in range(len(monedas)):
        for j in range(monedas[i], len(tbl)):
            if monedas[i] <= j:
                tbl[j] = (tbl[j] + tbl[j - monedas[i]]) % 1000000007

    print(tbl[cantidad])
