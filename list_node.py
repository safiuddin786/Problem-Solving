# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
result = ListNode()
p = result
n3 = 239
while(n3 > 0):
    p.val = n3 % 10
    p.next = ListNode()
    p = p.next
    n3 = n3//10
while(result != None):
    print(result.val)
    result = result.next