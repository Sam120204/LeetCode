class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        triangle = []
        for i in range(numRows):
            row = (i+1) * [1]
            for j in range(1, i):
                row[j] = triangle[i-1][j] + triangle[i-1][j-1]
            triangle.append(row)
        return triangle
        