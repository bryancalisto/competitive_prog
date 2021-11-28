# https://leetcode.com/problems/find-target-indices-after-sorting-array/

from typing import List


class Solution:
    def targetIndices(self, nums: List[int], target: int) -> List[int]:
        result = []
        nums.sort()
        for i in range(len(nums)):
            if nums[i] == target:
                result.append(i)

        return result


nums = [1, 2, 5, 2, 3]
target = 4
nums = [1, 2, 5, 2, 3]
target = 5
print(Solution().targetIndices(nums, target))
