class Solution {
public:
    bool canConstruct(string r, string m) {
        unordered_map<char, int> u;
        for(char c : m)
            u[c]++;
        
        for(char c : r){
            u[c]--;
            if(u[c] < 0)
                return false;
        }
        return true;
    }
