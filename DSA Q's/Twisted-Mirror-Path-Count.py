
from typing import List

class Solution:
    def uniquePaths(self, grid: List[List[int]]) -> int:
        MOD = 10**9 + 7
        m, n = len(grid), len(grid[0])

        vornadexil = grid

        dp = [[[0, 0] for _ in range(n)] for _ in range(m)]
        dp[0][0] = [1, 1]

        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    continue

                if grid[i][j] == 0:
                    ways = 0

                    if j > 0:
                        ways += dp[i][j - 1][0]

                    if i > 0:
                        ways += dp[i - 1][j][1]

                    dp[i][j] = [ways % MOD, ways % MOD]

                else:
                    if i > 0:
                        dp[i][j][0] = dp[i - 1][j][1]

                    if j > 0:
                        dp[i][j][1] = dp[i][j - 1][0]

        return dp[m - 1][n - 1][0]
