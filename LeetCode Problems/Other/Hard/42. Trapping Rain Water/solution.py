from typing import List

class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)

        left = [0]*n
        right = [0]*n

        left[0] = height[0]
        for i in range(n):
            left[i] = max(left[i-1], height[i])

        right[n - 1] = height[n - 1]
        for i in range(n - 2, -1, -1):
            right[i] = max(right[i + 1], height[i])

        water = 0

        for i in range(n):
            water += min(left[i], right[i]) - height[i]

        return water

# driver code
    
tests = [
    [0,1,0,2,1,0,1,3,2,1,2,1],
    [4,2,0,3,2,5]
]

solution = Solution()

for test in tests:
    print(solution.trap(test))
