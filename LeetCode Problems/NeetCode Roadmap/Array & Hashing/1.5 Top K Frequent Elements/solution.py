from typing import List
from collections import Counter

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        unique = Counter(nums)
        
        unique_list = [[x, unique[x]] for x in unique]
        unique_list.sort(key=lambda e: e[1], reverse=True)

        elems = [x[0] for x in unique_list]

        return elems[:k]
