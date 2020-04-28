class Solution:
    def searchInsert(self, nums, target: int) -> int:
        first = 0 
        last = len(nums)-1
        
        pos = -1
        
        while(first<=last and pos==-1):
            mid = int((first+last)/2)
            if(target>nums[mid]):
                first = mid+1 
            
            if(target<nums[mid]):
                last = mid -1
            
            if(target==nums[mid]):
                pos = mid
        
        if(pos!=-1):
            print(pos)
        else:
            first = 0
            last = len(nums)-1
            while(first<=last):
                mid = int((first+last)/2)
                if(target>nums[mid]):
                    first = mid+1 

                if(target<nums[mid]):
                    last = mid -1
                print("the middle is ",mid)

            if(nums[mid]<target):
                mid = mid + 1
            print(mid)
            
        
            
testCase = Solution()
testCase.searchInsert([1,3,5,6],2)