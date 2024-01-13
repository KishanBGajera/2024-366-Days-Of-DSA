from typing import List

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        # Solution
        # a `hash_set` which will keep record of already present elements
        hash_set = set()
        for n in nums:
            if n in hash_set:
                return True
            else:
                hash_set.add(n)
        return False
   
# driver code

# tests = [
#     [1,2,3,1],
#     [1,2,3,4],
#     [1,1,1,3,3,4,3,2,4,2]
# ]

# solution = Solution()

# for test in tests:
#     print(solution.containsDuplicate(test))