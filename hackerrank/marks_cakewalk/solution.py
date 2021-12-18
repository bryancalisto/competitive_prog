from typing import List


def marcsCakewalk(calorie: List):
    # Write your code here
    miles = 0
    calorie.sort(reverse=True)
    for i in range(len(calorie)):
        miles += pow(2, i) * calorie[i]
    return miles


calories = [5, 10, 7]
print(marcsCakewalk(calories))
