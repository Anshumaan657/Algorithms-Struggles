
class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        n = len(nums)

        target = sorted(nums, key=lambda x: (sum(map(int, str(x))), x))

        pos = {num: i for i, num in enumerate(target)}
        visited = [False] * n
        swaps = 0

        for i in range(n):
            if visited[i] or pos[nums[i]] == i:
                continue

            cycle_size = 0
            j = i

            while not visited[j]:
                visited[j] = True
                j = pos[nums[j]]
                cycle_size += 1

            swaps += cycle_size - 1

        return swaps
