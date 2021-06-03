class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseBetween(self, head: ListNode, left: int, right: int) -> ListNode:
        dummy = ListNode(0, head)
        count = right - left
        if count == 0:
            return head
        pre = dummy
        while left > 1:
            left -= 1
            pre = pre.next
        stack = []
        shead = pre.next
        while count >= 0:
            stack.append(shead)
            shead = shead.next
            count -= 1

        while stack:
            pre.next = stack.pop()
            pre = pre.next
        pre.next = shead
        return dummy.next


if __name__ == '__main__':
    head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
    s = Solution()
    ans = s.reverseBetween(head, 2, 4)
