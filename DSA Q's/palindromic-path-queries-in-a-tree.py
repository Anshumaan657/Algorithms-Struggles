from typing import List


class Solution:
    def palindromePath(self, n: int, edges: List[List[int]], s: str, queries: List[str]) -> List[bool]:
        adj = [[] for _ in range(n)]
        for a, b in edges:
            adj[a].append(b)
            adj[b].append(a)

        LOG = max(1, n.bit_length())
        up = [[0] * n for _ in range(LOG)]
        depth = [0] * n
        tin = [0] * n
        tout = [0] * n
        base = [0] * n            # root-to-node parity mask using the initial string
        chars = [ord(c) - 97 for c in s]

        # iterative DFS from node 0
        timer = 0
        base[0] = 1 << chars[0]
        stack = [(0, 0)]          # (node, next neighbor index)
        tin[0] = timer
        timer += 1
        ptr = [0] * n
        while stack:
            u, _ = stack[-1]
            if ptr[u] < len(adj[u]):
                v = adj[u][ptr[u]]
                ptr[u] += 1
                if v == up[0][u] and u != 0 or (u == 0 and v == 0):
                    continue
                if v == up[0][u]:
                    continue
                up[0][v] = u
                depth[v] = depth[u] + 1
                base[v] = base[u] ^ (1 << chars[v])
                tin[v] = timer
                timer += 1
                stack.append((v, 0))
            else:
                tout[u] = timer - 1
                stack.pop()

        for k in range(1, LOG):
            prev, cur = up[k - 1], up[k]
            for v in range(n):
                cur[v] = prev[prev[v]]

        def lca(a: int, b: int) -> int:
            if depth[a] < depth[b]:
                a, b = b, a
            diff = depth[a] - depth[b]
            k = 0
            while diff:
                if diff & 1:
                    a = up[k][a]
                diff >>= 1
                k += 1
            if a == b:
                return a
            for k in range(LOG - 1, -1, -1):
                if up[k][a] != up[k][b]:
                    a = up[k][a]
                    b = up[k][b]
            return up[0][a]

        # Fenwick tree (XOR): range update, point query
        tree = [0] * (n + 2)

        def add(i: int, val: int) -> None:
            i += 1
            while i <= n + 1:
                tree[i] ^= val
                i += i & -i

        def prefix(i: int) -> int:
            i += 1
            res = 0
            while i > 0:
                res ^= tree[i]
                i -= i & -i
            return res

        def point_mask(x: int) -> int:
            return base[x] ^ prefix(tin[x])

        ans = []
        for q in queries:
            parts = q.split()
            if parts[0] == "update":
                u = int(parts[1])
                c = ord(parts[2]) - 97
                if c != chars[u]:
                    delta = (1 << chars[u]) ^ (1 << c)
                    chars[u] = c
                    add(tin[u], delta)
                    add(tout[u] + 1, delta)
            else:
                u, v = int(parts[1]), int(parts[2])
                l = lca(u, v)
                mask = point_mask(u) ^ point_mask(v) ^ (1 << chars[l])
                ans.append(mask & (mask - 1) == 0)
        return ans
