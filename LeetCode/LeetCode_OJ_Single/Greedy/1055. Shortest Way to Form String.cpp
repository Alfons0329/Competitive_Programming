class Solution {
public:
    int shortestWay(string source, string target) {
        int n = target.size(), m = source.size(), res = 0;
        
        for(int i = 0; i < n;){
            int j = 0;
            int flg = 0;
            for(int j = 0; j < m;){
                // at least one match for the source vs target, increment both indices
                if(target[i] == source[j]){
                    i++;
                    j++;
                    flg = 1; 
                }
                // try the best matching target with source, if not match, increment the position in source
                else{
                    j++;                    
                }
            }
            // does not match any character in source vs target, early stop
            if(!flg){
                return -1;
            }
            // complete a matching
            res++;
        }
        return res;
    }
};