class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // init
        int res = 0, tmp_res = 0, n = s.size();
        unordered_set<char> st;
        
        // solve
        char c = 0;
        int i = 0, j = 0;
        while(i < n && j < n){
            if(st.find(s[j]) == st.end()){
                st.insert(s[j++]);
                res = max(res, j - i);
            }
            else{
                st.erase(st.find(s[i++]));
            }
        }
        
        return res;
    }
};