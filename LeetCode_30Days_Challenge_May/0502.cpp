class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int res = 0;
        for(char c1 : J){
            for(char c2 : S){
                res += c1 == c2;
            }
        }
        return res;
    }
};
