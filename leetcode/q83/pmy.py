class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return head
        dummy = ListNode(0, None)
        dummy_head = dummy
        duque = []
        while head:
            if not duque:
                duque.append(head)
            elif duque[-1].val == head.val:
                duque.append(head)
            else:
                dummy.next = duque[0]
                dummy = dummy.next
                duque.clear()
                duque.append(head)
            head = head.next
        dummy.next = duque[0]
        dummy.next.next = None
        return dummy_head.next

