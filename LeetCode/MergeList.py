# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode: 
        if l1 == None and l2 == None:
            return None
        elif l1 == None:
            return l2
        elif l2 == None:
            return l1
            
        start = None
        while l1 and l2:
            if(l1.val<=l2.val):
                if start==None:
                    l3 = ListNode(l1.val)
                    start = l3 
                    l1 = l1.next
                else:
                    p = ListNode(l1.val)
                    temp = start 
                    start = p 
                    p.next = temp
                    l1 = l1.next
            else:
                if(l1.val>=l2.val):
                    if start==None:
                        l3 = ListNode(l2.val)
                        start = l3 
                        l2 = l2.next
                    else:
                        p = ListNode(l2.val)
                        temp = start 
                        start = p 
                        p.next = temp
                        l2 = l2.next

        while l1:
            if start==None:
                    l3 = ListNode(l1.val)
                    start = l3 
                    l1 = l1.next
            else:
                p = ListNode(l1.val)
                temp = start 
                start = p 
                p.next = temp
                l1 = l1.next
        while l2!=None:
            if start==None:
                l3 = ListNode(l1.val)
                start = l3 
                l2 = l2.next
            else:
                p = ListNode(l2.val)
                temp = start 
                start = p 
                p.next = temp
                l2 = l2.next
        
        revL = start
        revList = []
        while(revL!=None):
            revList.append(revL.val)
            revL = revL.next
        
        startRev = None
        for x in revList:
            if startRev == None:
                p = ListNode(x)
                startRev = p
            else:
                p = ListNode(x)
                temp = startRev
                startRev = p 
                p.next = temp
        
        return(startRev)    
        


                    
        