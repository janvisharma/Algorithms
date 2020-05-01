class Solution:
    def removeDuplicates(self, nums) -> int:
        for x in nums: 
            print("for val x ",x)
            start = nums.index(x)+1

            for y in nums[start::]:
                if(x==y):
                    nums.remove(y)
        print(nums)

testCase = Solution()
testCase.removeDuplicates(['1','1','2','2','2'])

'''
Better soln:
    class Solution:
    def removeDuplicates(self, nums) -> int:
        i = 0
        while i < len(nums)-1:
            if nums[i] == nums[i+1]:
                del nums[i]
            else:
                i += 1
        return len(nums)
'''