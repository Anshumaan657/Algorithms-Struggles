class Solution:
    def climbStairs(self, n: int, costs: list[int]) -> int:
        dp = [float("inf")] * (n + 1)
        dp[0] = 0

        for j in range(1, n + 1):
            for jump in (1, 2, 3):
                if j >= jump:
                    cost = costs[j - 1] + jump * jump
                    dp[j] = min(dp[j], dp[j - jump] + cost)

        return dp[n]
