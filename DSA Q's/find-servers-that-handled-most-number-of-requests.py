import heapq

class Solution:
    def busiestServers(self, k, arrival, load):
        busy = []
        bit = [0] * (k + 1)
        handled = [0] * k

        def add(index, value):
            index += 1
            while index <= k:
                bit[index] += value
                index += index & -index

        def prefix_sum(index):
            result = 0
            index += 1
            while index > 0:
                result += bit[index]
                index -= index & -index
            return result

        def find_kth(target):
            index = 0
            step = 1 << (k.bit_length() - 1)

            while step:
                next_index = index + step
                if next_index <= k and bit[next_index] < target:
                    index = next_index
                    target -= bit[next_index]
                step //= 2

            return index

        for server in range(k):
            add(server, 1)

        for i, time in enumerate(arrival):
            while busy and busy[0][0] <= time:
                finish, server = heapq.heappop(busy)
                add(server, 1)

            available = prefix_sum(k - 1)

            if available == 0:
                continue

            start = i % k
            before_start = prefix_sum(start - 1) if start > 0 else 0

            if available > before_start:
                server = find_kth(before_start + 1)
            else:
                server = find_kth(1)

            add(server, -1)
            handled[server] += 1
            heapq.heappush(busy, (time + load[i], server))

        maximum = max(handled)
        return [i for i in range(k) if handled[i] == maximum]
