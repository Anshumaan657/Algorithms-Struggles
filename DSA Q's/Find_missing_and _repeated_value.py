class Solution:
    def findMissingAndRepeatedValues(self, grid: list[list[int]]) -> list[int]:
        n = len(grid)
        size = n * n

        count = [0] * (size + 1)

        for row in grid:
            for num in row:
                count[num] += 1

        repeated = -1
        missing = -1

        for num in range(1, size + 1):
            if count[num] == 2:
                repeated = num
            elif count[num] == 0:
                missing = num

        return [repeated, missing]
