from bisect import bisect_left
from typing import List

class Solution:
    def findTheDistanceValue(self, arr1: List[int], arr2: List[int], d: int) -> int:
        arr2.sort()
        count = 0

        for x in arr1:
            # Find the closest element in arr2 to x
            i = bisect_left(arr2, x)

            ok = True
            # Check the element at or after x
            if i < len(arr2) and arr2[i] - x <= d:
                ok = False
            # Check the element before x
            if i > 0 and x - arr2[i - 1] <= d:
                ok = False

            if ok:
                count += 1

        return count
