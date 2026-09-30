class soultion:
    def maxDepth(self, s: str) -> int:
        depth = 0
        answer = []
        for ch in s:
            if ch == "(":
                depth = depth + 1
                answer.append(depth)
            elif ch == ")":
                answer.append(depth)
                depth = depth - 1
        return answer