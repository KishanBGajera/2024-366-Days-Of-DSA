class Solution:
    def tribonacci(self, n: int) -> int:
        if n == 0:
            return 0
        elif n == 1:
            return 1
        elif n == 2:
            return 1

        i = 3
        a, b, c = 0, 1, 1
        while i <= n:
            c, b, a = a + b + c, c, b
            i += 1
        return c