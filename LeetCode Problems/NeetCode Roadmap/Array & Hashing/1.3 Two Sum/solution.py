from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash_dict = {}

        for i, n in enumerate(nums):
            complement = target - n
            if complement in hash_dict:
                return [hash_dict[complement], i]
            hash_dict[n] = i

# driver code
            
# tests = [
#     [[2, 7, 11, 15], 9],
#     [[3, 2, 4], 6],
#     [[3, 3], 6]
# ]

# solution = Solution()

# for test in tests:
#     print(solution.twoSum(test[0], test[1]))