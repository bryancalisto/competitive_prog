# https://leetcode.com/problems/k-radius-subarray-averages/
from typing import List


class Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        diameter = k * 2 + 1
        result = [-1] * len(nums)
        start = 0
        count = 0
        sum = 0
        last = 0

        # for i in range(k, len(nums) - k):
        for i in range(len(nums)):
            count += 1
            sum += nums[i]
            if count == diameter:
                count -= 1
                # print(f'nums: {nums[i]}')
                result[i - k] = sum // diameter
                sum -= nums[start]
                start += 1
        return result


nums = [7, 4, 3, 9, 1, 8, 5, 2, 6]
k = 3
nums = [100000]
k = 0
print(Solution().getAverages(nums, k))
