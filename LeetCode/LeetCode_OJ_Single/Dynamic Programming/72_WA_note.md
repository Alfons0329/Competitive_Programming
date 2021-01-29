Thanks for the help in advance!

I think the problem lies in the initialization process, not viewing the solution but implement the initialization using my own idea. (if I change to the same logic as the solution tells, i.e. ![image](https://assets.leetcode.com/users/bug_exceeded/image_1583816295.png)
then I will have a wrong answer at "intention"  --> "execution" (997/1146)

and the code shwon below failed at 1143/1146 testcase
"pneumonoultramicroscopicsilicovolcanoconiosis"
"ultramicroscopically"

* Step 1: init a dp matrix where dp[i][j] means the shortest edit distance converting from word1[0..i] to word2[0..j]
* Step 2-1: init all dp[i][0] (i.e. changing from word[0..i] to word2[0]), dp[i][0] = dp[i - 1] + 1 if word1[i] != word2[0] else dp[i - 1]   
* Step 2-2: init all dp[0][j] (i.e. changing from word[0] to word2[0..j]), dp[0][j] = dp[j - 1] + 1 if word2[j] != word1[0] else dp[j - 1]
* Step 3: dp for 3 situations for word1[i] != word2[j]
    * the result is obtained from delete, then query dp[i - 1, j] + 1(current use one step as delete) 
    * the result is obtained from insert, then query dp[i, j - 1] + 1(current use one step as delete)
    * the result is obtained from change, then query dp[i - 1, j - 1] + 1(current use one step as delete)
    * search for the min of the three
    * note: suppose word1[i] == word2[j] then simply query dp[i - 1][j - 1] for the subproblem
```cpp
/*

*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int res = 0;
        int len1 = word1.size();
        int len2 = word2.size();
        // if len2 just return the length of len1 with deleting all the chars
        if(!len2){
            return len1;
        }
        else if(!len1){
            return len2;
        }
        
        // Step 1:
        vector<vector<int> > dp(len1, vector<int>(len2, 0));
        // Step 2-1:
        dp[0][0] = (word1[0] != word2[0]);
        for(int i = 1; i < len1; i++){
            dp[i][0] = (word1[i] != word2[0]) ? dp[i - 1][0] + 1 : dp[i - 1][0];
            // dp[i][0] = i;
        }
        // Step 2-2:
        for(int j = 1; j < len2; j++){
            dp[0][j] = (word1[0] != word2[j]) ? dp[0][j - 1] + 1 : dp[0][j - 1];
            // dp[0][j] = j;
        }
        // Step 3:
        for(int i = 1; i < len1; i++){
            for(int j = 1; j < len2; j++){
                if(word1[i] == word2[j]){
                    dp[i][j] = dp[i - 1][j - 1];         
                }
                else{
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;         
                }
            }
        }
        
        return dp[len1 - 1][len2 - 1];
    }
};
```