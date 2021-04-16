class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        duque = []
        dummy = ListNode(0, None)
        dummy_head = dummy
        while head:
            if not duque:
                duque.append(head)
            elif duque[-1].val == head.val:
                duque.append(head)
            elif len(duque) > 1:
                duque.clear()
                duque.append(head)
            else:
                dummy.next = duque.pop()
                dummy = dummy.next
                duque.append(head)
            head = head.next
        if len(duque) == 1:
            dummy.next = duque.pop()
            dummy = dummy.next
        else:
            dummy.next = None
        return dummy_head.next



