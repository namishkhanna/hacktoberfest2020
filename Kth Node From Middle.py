class Solution:
    # @param A : head node of linked list
    # @param B : integer
    # @return an integer
    def solve(self, A, B):
        slow=A
        fast=A
        mid=1
        while fast and fast.next:
            mid+=1
            slow=slow.next
            fast=fast.next.next
        if mid-B<=0:
            return -1
        k=1
        #if mid==B:
           # return slow.val
        while  A  and k!=mid-B :
            A=A.next
            k+=1
            
            
        return A.val
