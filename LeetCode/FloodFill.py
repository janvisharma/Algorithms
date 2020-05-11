class Solution:
    def floodFill(self, image, sr, sc, newColor):
        temp = image[sr][sc]  
        def recFlood(image,sr,sc,newColor):
            if image[sr][sc]==newColor:
                return
            else:          
                image[sr][sc]=newColor
                lenr = len(image)
                lenc = len(image[0])
                if(sr-1>=0):
                    if(image[sr-1][sc]==temp):
                        recFlood(image,sr-1,sc,newColor)
                if(sr+1<lenr):
                    if(image[sr+1][sc]==temp):
                        recFlood(image,sr+1,sc,newColor)
                if(sc+1<lenc):
                     if(image[sr][sc+1]==temp):
                        recFlood(image,sr,sc+1,newColor)
                if(sc-1>=0):
                     if(image[sr][sc-1]==temp):
                        recFlood(image,sr,sc-1,newColor)
        
        recFlood(image,sr,sc,newColor)
        print(image)   

testCase = Solution()
testCase.floodFill([[1,1,1],[1,1,0],[1,0,1]],1,1,2)