class ListNode:
    def __init__(self, val = 0, Next = None):
        self.val = val
        self.Next = Next

node = ListNode()
def increaseNode(start : ListNode, i : int):
    if i == 6:
        return start
    
    print(i)
    start.Next= ListNode(i)
    return increaseNode(start.Next, i + 1)



def getNum(node : ListNode) -> str :
    if node.Next == None:
        return str(node.val)
    return  str(getNum(node.Next)) + str(node.val)

print(getNum(increaseNode(node,0))
print(getNum(node))
####################################LeetCode problem : Add Two Numbers
      
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        
        def getNum(node : Optional[ListNode]) -> str : 
            if node.next == None:
                return str(node.val)
            return  str(getNum(node.next)) + str(node.val)
        
        num1 = int(getNum(l1))
        num2 = int(getNum(l2))
        prod = list(str(num1 + num2))
        prod.reverse()
        start = ListNode(prod[0])
        def constructList(start, i : int):
            if i == len(prod):
                return start
            start.next = ListNode(prod[i])
            return constructList(start.next, i + 1)
        
        constructList(start,1)
        return start
    
