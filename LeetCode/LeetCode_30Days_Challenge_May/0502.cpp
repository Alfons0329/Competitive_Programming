class Solution {
public:
    int numJewelsInStones(string J, string S) {
        // O(J + S)
        int res = 0;
        unordered_map<char, int> us;
        for(char c : S)
            us[c]++;
        
        for(char c : J){
            if(us.count(c))
                res += us[c];
        }
        return res;
    }
};
