# https://www.hackerrank.com/challenges/cats-and-a-mouse/problem
def catAndMouse(x, y, z):
    d1 = abs(z-x)
    d2 = abs(z-y)

    if d1 == d2:
        return 'Mouse C'
    elif d1 < d2:
        return 'Cat A'
    else:
        return 'Cat B'


x, y, z = 1, 2, 3
print(catAndMouse(x, y, z))
x, y, z = 1, 3, 2
print(catAndMouse(x, y, z))
