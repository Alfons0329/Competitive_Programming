class Solution:
    def printVertically(self, s: str) -> List[str]:
        res = list()
        ss = s.split()
        maxlen = 0
        for i in ss:
            maxlen = max(maxlen, len(i))
        
        for j in range(maxlen):
            tmp = []
            for i in range(len(ss)):
                if j >= len(ss[i]):
                   tmp.append(' ')
                else:
                    tmp.append(ss[i][j])
            
            res.append(''.join(tmp).rstrip())
            
        return res