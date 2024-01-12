from typing import List

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        size = len(nums)
        non_zero = -1
        ptr = 0

        for i in range(size):
            if nums[i] != 0:
                nums[i], nums[ptr] = nums[ptr], nums[i]
                ptr += 1
        
        for i in range(ptr, size):
            nums[i] = 0

# driver code

tests = [
    [0, 1, 0, 3, 12],
    [0]
]

solution = Solution()

for test in tests:
    solution.moveZeroes(test)
    print(test)
