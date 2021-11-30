# https://www.hackerrank.com/challenges/between-two-sets/problem
def getTotalX(a, b):
    result = 0

    for i in range(a[-1], 101):
        if all(i % x == 0 for x in a) and all(x % i == 0 for x in b):
            result += 1

    return result


a = [2, 4]
b = [16, 32, 96]
print(getTotalX(a, b))
