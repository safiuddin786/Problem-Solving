from typing import List, Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def helper(self,start,end) -> List[TreeNode]:
        x = []
        if(start > end):
            return [None]
        elif(start == end):
            return [TreeNode(val=start)]
        for i in range(start,end+1,1):
            l = Solution().helper(start,i-1)      
            r = Solution().helper(i+1,end)        
            for left in l:
                for right in r:
                    root = TreeNode(val=i)
                    root.left = left
                    root.right = right
                    x.append(root)
        return x
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        return Solution().helper(1,n)
print(Solution().generateTrees(3))