def toMinutesArray(times: str):
    res = [0, 0]
    startEnd = times.split()
    hourMin = startEnd[0].split(':')
    res[0] = int(hourMin[0]) * 60 + int(hourMin[1])
    hourMin = startEnd[1].split(':')
    res[1] = int(hourMin[0]) * 60 + int(hourMin[1])
    return res


MAX_MINS = 1500

N = int(input())
table = [0] * MAX_MINS
res = 0

for i in range(N):
    startEnd = toMinutesArray(input())
    table[startEnd[0]] += 1
    table[startEnd[1]] -= 1

for i in range(1, MAX_MINS):
    table[i] += table[i-1]
    res = max(res, table[i])

print(res)
