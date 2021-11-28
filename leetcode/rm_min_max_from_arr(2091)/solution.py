# https://leetcode.com/problems/removing-minimum-and-maximum-from-array/
from typing import List


class Solution:
    def minimumDeletions(self, nums: List[int]) -> int:
        n = len(nums)
        minim = 1000000
        maxim = -1000000
        minimI = 0
        maximI = 0

        for i in range(len(nums)):
            if nums[i] < minim:
                minim = nums[i]
                minimI = i
            if nums[i] > maxim:
                maxim = nums[i]
                maximI = i

        minIndex = min(minimI, maximI)
        maxIndex = max(minimI, maximI)

        return min(n-maxIndex + minIndex + 1, min(n-minIndex, maxIndex+1))


nums = [2, 10, 7, 5, 4, 1, 8, 6]
nums = [101]
nums = [0, -4, 19, 1, 8, -2, -3, 5]
print(Solution().minimumDeletions(nums))
