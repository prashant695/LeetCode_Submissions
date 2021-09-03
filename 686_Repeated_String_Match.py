class Solution(object):
    def repeatedStringMatch(self, a, b):
        a2=a
        cnt=1
        while(1):
            if b in a:
                return cnt
            else:
                if(len(a))>=(50000):
                    return -1
                a+=a2
                cnt+=1
        return cnt        