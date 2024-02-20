def isvowel(c):
    return c in "aeiouAEIOU"

class Solution:
    def reverseVowels(self, s: str) -> str:
        front = 0
        rear = len(s) - 1
        s_copy = list(s)
        while front <= rear:
            if not isvowel(s_copy[front]):
                front += 1
                continue
            if not isvowel(s_copy[rear]):
                rear -= 1
                continue
            
            s_copy[front], s_copy[rear] = s_copy[rear], s_copy[front]
            front += 1
            rear -= 1

        return "".join(s_copy)