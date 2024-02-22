from typing import List

class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        prefix = [0]
        prefix.append(gain[0])

        for g in gain[1:]:
            prefix.append(prefix[-1] + g)
        print(prefix)
        return max(prefix)