class Solution {
public:
    bool canConstruct(string r, string m) {
        unordered_map<char, int> u1; // magazine
        unordered_map<char, int> u2; // ransomNote
        for(char c : m){
            u1[c]++;
        }
        for(char c : r){
            u2[c]++;
        }
        
        for(auto it = u2.begin(); it != u2.end(); it++){
            char c = it -> first;
            if(u1.count(c)){
                if(it -> second > u1[c]){
                    return false;
                }
            }
            else{
                return false;
            }
        }
        return true;
    }
};
