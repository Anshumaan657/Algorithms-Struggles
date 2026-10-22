from typing import List

class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)

        def get_cost(arr):
            start = arr.index(0)

            for i in range(n):
                if arr[(start + i) % n] != i:
                    return -1

            return start

        answer = float("inf")

        # Original orientation
        cost = get_cost(nums)

        if cost != -1:
            answer = min(answer, cost, n - cost + 2)

        # Reversed orientation
        cost = get_cost(nums[::-1])

        if cost != -1:
            answer = min(
                answer,
                cost + 1,          # reverse, then rotate
                n - cost + 1        # rotate, then reverse
            )

        return -1 if answer == float("inf") else answer
