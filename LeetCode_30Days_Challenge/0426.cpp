class Solution {
public:
    int dp[1005][1005];
    int longestCommonSubsequence(string s1, string s2) {
        int res = 0;
        memset(dp, 0, sizeof(dp));
        
        int len1 = s1.size(), len2 = s2.size();
        for(int i = 1; i <= len1; i++){
            for(int j = 1; j <= len2; j++){
                if(s1[i - 1] == s2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } 
                else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        
        int i = len1, j = len2, idx = dp[len1][len2] - 1;
        string LCS("");
        LCS.resize(dp[len1][len2]);
        while(i >= 1 && j >= 1){
            if(s1[i - 1] == s2[j - 1]){
                LCS[idx--] = s1[i - 1];
                i--;
                j--;
            } 
            else if(dp[i - 1][j] > dp[i][j - 1]){
                i--;
            }
            else{
                j--;
            }
        }
        
        cout << "LCS: " << LCS << '\n';
        return dp[len1][len2];
    }
};
