def hurdleRace(k, height):
    return max(0, max(height) - k)


doses = 0 + 3
k = 1 + 3
height = [1, 4, 3, 3, 2]
print(hurdleRace(k, height))
