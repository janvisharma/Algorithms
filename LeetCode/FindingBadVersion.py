# May 1st 2020 Challenge

# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution:
    def firstBadVersion(self, n):
        first = 1
        last = n 
        key = n
        while(first<=last):
            mid = int((first+last)/2)
            if(isBadVersion(mid)==False):
                first = mid + 1
            if(isBadVersion(mid)):
                last = mid - 1
                if(mid<key):
                    key = mid
        
        return key
            