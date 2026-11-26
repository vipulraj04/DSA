class Solution(object):
    def canAliceWin(self, n):
        """
        :type n: int
        :rtype: bool
        """
        helper=10
        count=0
        while n>= helper:
            n-=helper
            helper=helper-1
            count=count+1

        return count%2==1