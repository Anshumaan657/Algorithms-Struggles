class Solution:
    def sumCounts(self, nums):
        n = len(nums)

        total_sum = [0] * (4 * n)
        total_square = [0] * (4 * n)
        lazy = [0] * (4 * n)

        def apply(node, left, right, value):
            length = right - left + 1

            total_square[node] += (
                2 * value * total_sum[node]
                + value * value * length
            )

            total_sum[node] += value * length
            lazy[node] += value

        def push(node, left, right):
            if lazy[node] == 0 or left == right:
                return

            middle = (left + right) // 2

            apply(node * 2, left, middle, lazy[node])
            apply(node * 2 + 1, middle + 1, right, lazy[node])

            lazy[node] = 0

        def update(node, left, right, update_left, update_right):
            if update_left > right or update_right < left:
                return

            if update_left <= left and right <= update_right:
                apply(node, left, right, 1)
                return

            push(node, left, right)

            middle = (left + right) // 2

            update(node * 2, left, middle, update_left, update_right)
            update(node * 2 + 1, middle + 1, right, update_left, update_right)

            total_sum[node] = total_sum[node * 2] + total_sum[node * 2 + 1]
            total_square[node] = (
                total_square[node * 2]
                + total_square[node * 2 + 1]
            )

        last_position = {}
        answer = 0

        for right in range(n):
            value = nums[right]
            previous = last_position.get(value, -1)

            update(
                1,
                0,
                n - 1,
                previous + 1,
                right
            )

            answer += total_square[1]
            last_position[value] = right

        return answer % (10**9 + 7)
