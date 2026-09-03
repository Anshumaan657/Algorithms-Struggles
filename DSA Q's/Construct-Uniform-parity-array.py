from typing import List

class Solution:
    def uniformArray(self, nums1: List[int]) -> bool:
        minimum = min(nums1)

        
        if minimum % 2 == 1:
            return True

       
        for num in nums1:
            if num % 2 == 1:
                return False

        return True