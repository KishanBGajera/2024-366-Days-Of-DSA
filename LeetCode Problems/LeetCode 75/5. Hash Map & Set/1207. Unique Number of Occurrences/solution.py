from typing import List
from collections import Counter

class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        lookup = dict(Counter(arr))
        occurs = [lookup[key] for key in lookup]
        return len(occurs) == len(set(occurs))
