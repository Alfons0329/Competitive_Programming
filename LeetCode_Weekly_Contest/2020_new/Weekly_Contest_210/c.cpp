class Solution {
public:
    bool check_palin(string s) {
        for (auto i = 0; i < s.size() / 2; ++i){
            if (s[i] != s[s.size() - 1 - i]){
                return false;
            }
        }    
        
        return true;
    }
    
    bool check(string &a, string &b) {
        int i = 0, j = a.size() - 1;
        while (i < j && a[i] == b[j]) {
            i++;
            j--;
        }
        
        return check_palin(a.substr(i, j - i + 1)) ||
            check_palin(b.substr(i, j - i + 1));
    }
    
    bool checkPalindromeFormation(string a, string b) {
        return check(a, b) || check(b, a);
    }
};
