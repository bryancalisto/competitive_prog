from typing import List


class Solution:
    # BRUTE FORCE: time O(n^2), space O(1)
    # def maxProfit(self, prices: List[int]) -> int:
    #     result = 0
    #     minim = 10000000
    #     maxim = 0

    #     for i in range(len(prices)):
    #         for j in range(i+1, len(prices)):
    #             if prices[i] > prices[j]:
    #                 break
    #             else:
    #                 if prices[i] < minim:
    #                     minim = prices[i]
    #                     maxim = 0
    #                     print(f'minim {minim}')
    #                 if prices[j] > maxim:
    #                     maxim = prices[j]
    #                     print(f'maxim {maxim}')
    #                 result = max(result, maxim - minim)

    #     return result

    # time O(n), space O(1)
    def maxProfit(self, prices: List[int]) -> int:
        result = 0
        minim = prices[0]

        for price in prices:
            result = max(result, price - minim)
            minim = min(minim, price)

        return result


prices = [7, 1, 5, 3, 6, 4]  # 5
print(Solution().maxProfit(prices))
prices = [7, 6, 4, 3, 1]  # 0
print(Solution().maxProfit(prices))
prices = [2, 1, 2, 0, 1]  # 1
print(Solution().maxProfit(prices))
prices = [3, 2, 6, 5, 0, 3]  # 4
print(Solution().maxProfit(prices))
