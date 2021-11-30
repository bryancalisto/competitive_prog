# https://www.hackerrank.com/challenges/kangaroo/problem
def kangaroo(x1, v1, x2, v2):
    if v1 > v2 and (x2 - x1) % (v1-v2) == 0:
        return 'YES'

    return 'NO'


x1, v1, x2, v2 = 0, 3, 4, 2
print(kangaroo(x1, v1, x2, v2))
