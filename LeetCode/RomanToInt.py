class Solution(object):
    def romanToInt(self, s:str)->int:
        dict = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        sum=0
        k = 0
        n = len(s)
        for x in s:
            if k<=n-2:
                if dict.get(x)<dict.get(s[k+1]):
                    sum = sum - dict.get(x)
                    k = k + 1
                elif dict.get(x)>dict.get(s[k+1]):
                    sum = sum + dict.get(x)
                    k = k + 1
                elif dict.get(x)==dict.get(s[k+1]):
                    sum = sum + dict.get(x)
                    k = k + 1
            else:
                sum = sum + dict.get(x)
        return sum

testCase = Solution()
print(testCase.romanToInt("MCMXCIV"))
print(testCase.romanToInt('IV'))
