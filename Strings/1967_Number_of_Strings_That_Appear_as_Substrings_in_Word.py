class Solution(object):
    def numOfStrings(self, patterns, word):
        cnt = 0
        for i in patterns:
            if i in word:
                cnt+=1
                
        return cnt        
        