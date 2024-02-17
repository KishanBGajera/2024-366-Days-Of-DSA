class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        stack = []
        current_node = head
        while current_node:
            stack.append(current_node.val)
            current_node = current_node.next
        if stack:
            head = ListNode(stack.pop())
            def insert(head, next):
                current_node = head
                while current_node.next:
                    current_node = current_node.next
                current_node.next = ListNode(next)
            while stack:
                insert(head, stack.pop())
        return head