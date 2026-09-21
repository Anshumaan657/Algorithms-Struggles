class Solution:
    def generate(self, numRows: int) -> list[list[int]]:
        triangle = []
        for i in range (numRows):
            row = []
            for j in range (i+1):
                if j == 0 or j == i:
                    row.append(1)
                else:
                    above_left = triangle[i-1][j-1]
                    above_right = triangle[i-1][j]
                    row.append(above_left + above_right)

            triangle.append(row)

        return triangle    

            