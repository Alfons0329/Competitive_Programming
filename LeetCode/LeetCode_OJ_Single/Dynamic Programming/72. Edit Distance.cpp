/*
* Step 1: init a dp matrix where dp[i][j] means the shortest edit distance converting from word1[0..i] to word2[0..j]
* Step 2-1: init all dp[i][0] (i.e. changing from word1[0..i] to ""), to i (that is, keep deleting in the word1 to form word2)
* Step 2-2: init all dp[0][j] (i.e. changing from "" to word2[0..j]), to j (that is, keep inserting in the empty word1 to form word2)
* Step 3: dp for 3 situations for word1[i - 1] != word2[j - 1] (if word1[i - 1] == word2[j - 1], simply query the already-solved subproblem: dp[i - 1][j - 1])
    * the result is obtained from delete, then query dp[i - 1, j] + 1(current use one step as delete) 
    * the result is obtained from insert, then query dp[i, j - 1] + 1(current use one step as delete)
    * the result is obtained from change, then query dp[i - 1, j - 1] + 1(current use one step as delete)
    * search for the min of the three
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int res = 0;
        int len1 = word1.size();
        int len2 = word2.size();
        
        // Step 1:
        vector<vector<int> > dp(len1 + 1, vector<int>(len2 + 1, 0));
        
        // Step 2-1:
        dp[0][0] = 0;
        for(int i = 1; i <= len1; i++){
            dp[i][0] = i;
        }
        
        // Step 2-2:
        for(int j = 1; j <= len2; j++){
            dp[0][j] = j;
        }
        
        // Step 3:
        for(int i = 1; i <= len1; i++){
            for(int j = 1; j <= len2; j++){
                if(word1[i - 1] == word2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1];         
                }
                else{
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;         
                }
            }
        }
        
        return dp[len1][len2];
    }
};