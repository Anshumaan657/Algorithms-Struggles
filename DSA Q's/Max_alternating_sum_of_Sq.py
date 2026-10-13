from typing import List

class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        nums.sort(key=lambda x: x * x)

        n = len(nums)
        ans = 0

        for i in range(n):
            if i < n // 2:
                ans -= nums[i] ** 2
            else:
                ans += nums[i] ** 2

        return ans
