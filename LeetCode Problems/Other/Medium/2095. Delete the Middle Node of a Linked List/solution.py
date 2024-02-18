from typing import *

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return None

        fast = head
        slow = head
        slowback = None

        while fast and fast.next:
            slowback = slow
            slow = slow.next
            fast = fast.next.next

        if slowback:
            slowback.next = slow.next

        return head
            