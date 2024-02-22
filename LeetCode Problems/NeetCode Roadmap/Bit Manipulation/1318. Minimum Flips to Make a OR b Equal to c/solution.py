class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        a = bin(a)[2:]
        b = bin(b)[2:]
        c = bin(c)[2:]

        m = max(len(a), len(b), len(c))

        a = a.zfill(m)
        b = b.zfill(m)
        c = c.zfill(m)

        changes = 0

        for i in range(m):
            if int(a[i]) | int(b[i]) == int(c[i]):
                continue
            else:
                if c[i] == '0' and ((a[i] == '0' and b[i] == '1') or (a[i] == '1' and b[i] == '0')):
                    changes += 1
                elif c[i] == '0' and (a[i] == '1' and b[i] == '1'):
                    changes += 2
                elif c[i] == '1' and a[i] != '1' and b[i] != '1':
                    changes += 1
            
        return changes