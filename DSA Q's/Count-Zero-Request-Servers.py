from typing import List
from collections import defaultdict

class Solution:
    def countServers(self, n: int, logs: List[List[int]], x: int, queries: List[int]) -> List[int]:
        logs.sort(key=lambda l: l[1])
        order = sorted(range(len(queries)), key=lambda i: queries[i])

        cnt = defaultdict(int)   # server_id -> requests in current window
        active = 0               # number of servers with at least one request in window
        left = right = 0         # window is logs[left:right]
        ans = [0] * len(queries)

        for i in order:
            q = queries[i]

            # add logs with time <= q
            while right < len(logs) and logs[right][1] <= q:
                sid = logs[right][0]
                if cnt[sid] == 0:
                    active += 1
                cnt[sid] += 1
                right += 1

            # remove logs with time < q - x
            while left < right and logs[left][1] < q - x:
                sid = logs[left][0]
                cnt[sid] -= 1
                if cnt[sid] == 0:
                    active -= 1
                left += 1

            ans[i] = n - active

        return ans
