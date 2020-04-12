class Solution:
    def reverse(self,x):
        rev = 0 
        temp = 0
        INTMAX = 2**31 - 1 # considering a 32 bit signed integer
        ctr = -1
        if(x<0):
            # for negative numbers the mod works differently 
            x = abs(x) 
            ctr = 1

        while x!=0:
            pop = x%10
            x = int(x/10)
            """
            for overflow condition in 32 signed bit integer 
            overflow occurs when 
                rev*10 >= INTMAX 
                Condition 1: rev*10>INTMAX def overflow
                Condition 2: rev*10=INTMAX then we need to check   
                             the value of pop because
                             rev*10 = 2147483640
                             INTMAX = 2147483647
                             pop>7 will cause overflow! 
            """

            if rev*10 > INTMAX:
                return 0 # overflow! 
            
            if rev*10 == INTMAX:
                if pop>7:
                    return 0 # overflow! 

            temp = rev*10 + pop
            rev = temp
            temp = 0
        
        if ctr == 1:
            return -rev
        else:
            return rev

num = Solution()
val = input("Enter the integer you wish to reverse: ")
print("The reverse integer is: "+str(num.reverse(int(val))))