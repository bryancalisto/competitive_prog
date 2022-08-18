# 1000000007

N = int(input())
monedas = list(map(int, input().split(' ')))
M = int(input())
nValores = 5001  # Segun constraint de maximo valor y +1 porque incluye el 0

tbl = [[0 for i in range(N)] for j in range(nValores)]

for iMoneda in range(N):  # Si tienes un valor de 0 (fila 0), necesitas solo un set para representar ese valor: {}
    tbl[0][iMoneda] = 1

for valor in range(nValores):
    for iMoneda in range(N):
        if iMoneda > 0:
            tbl[valor][iMoneda] = tbl[valor][iMoneda-1]

        restante = valor - monedas[iMoneda]

        if restante >= 0:
            tbl[valor][iMoneda] = (tbl[valor][iMoneda] + tbl[restante][iMoneda]) % 1000000007


for i in range(M):
    valor = int(input())
    print(tbl[valor][N - 1])
