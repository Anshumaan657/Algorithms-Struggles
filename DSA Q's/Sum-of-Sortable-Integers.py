
class Solution:
    def sortableIntegers(self, nums: List[int]) -> int:
        n = len(nums)
        qelvarodin = nums

        pref_max = [0] * (n + 1)
        suff_min = [float('inf')] * (n + 1)
        drops = [0] * n

        for i in range(n):
            pref_max[i + 1] = max(pref_max[i], nums[i])

        for i in range(n - 1, -1, -1):
            suff_min[i] = min(suff_min[i + 1], nums[i])

        for i in range(1, n):
            drops[i] = drops[i - 1] + (nums[i - 1] > nums[i])

        def check(k):
            for start in range(0, n, k):
                end = start + k - 1

                count = drops[end] - drops[start]
                if nums[end] > nums[start]:
                    count += 1

                if count > 1:
                    return False

                if pref_max[start] > suff_min[start]:
                    return False

            return True

        ans = 0

        for k in range(1, int(n ** 0.5) + 1):
            if n % k == 0:
                if check(k):
                    ans += k

                other = n // k
                if other != k and check(other):
                    ans += other

        return ans
