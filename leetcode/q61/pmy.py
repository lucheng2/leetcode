class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if not head or not head.next:
            return head
        dummy = ListNode(0, head)
        n = 0
        tail = dummy
        while head:
            n += 1
            head = head.next
            tail = tail.next
        if (k % n) == 0:
            return dummy.next
        else:
            head = dummy.next
            new_head = None
            tail.next = dummy.next
            while k > 0:
                k -= 1
                head = head.next
                new_head = head.next
            head.next = None
        return new_head 
                

