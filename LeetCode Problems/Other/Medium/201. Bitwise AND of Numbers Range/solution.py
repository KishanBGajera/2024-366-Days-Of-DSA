class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        shiftcount = 0

        while(left != right and left > 0):
            shiftcount += 1
            left = left >> 1
            right = right >> 1
            
        return left << shiftcount
