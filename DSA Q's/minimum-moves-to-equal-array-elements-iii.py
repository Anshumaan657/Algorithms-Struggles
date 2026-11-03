class Solution:
    def minMoves(self, nums: List[int]) -> int:
        largest = max(nums)
        moves = 0
        for value in nums:
            moves += largest - value
        return moves
