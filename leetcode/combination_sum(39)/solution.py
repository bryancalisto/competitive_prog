from typing import List


class Solution:
    result = []

    def helper(self,  candidates: List[int], target: int, currentElems: List[int], remaining: int, start: int) -> List[List[int]]:
        if remaining < 0:
            return
        elif remaining == 0:
            self.result.append(currentElems.copy())
        else:
            for i in range(start, len(candidates)):
                currentElems.append(candidates[i])
                self.helper(candidates, target, currentElems, remaining - candidates[i], i)
                currentElems.pop(-1)

    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        self.result = []  # Leetcode requires you to manually reset the variables that are outside your function. If not, tests cases errors are probable
        self.helper(candidates, target, [], target, 0)
        return self.result


candidates = [2, 3, 6, 7]
target = 7
candidates = [2, 3, 5]
target = 8

print(Solution().combinationSum(candidates, target))
