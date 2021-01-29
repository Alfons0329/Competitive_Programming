class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int n = s.size(), sum = 0; // + for shift right and - for shift left
        
        for(auto vi : shift){
            sum += (vi[0] == 1) ? vi[1] : -vi[1];
        }
        
        string res; // the result string
        // no longer need to shift
        if(sum == -n || sum == n || sum == 0){
            return s;
        }
        // if shift right
        if(sum > 0){
            sum %= n;
            res = s.substr(n - sum, sum) + s.substr(0, n - sum); 
        } 
        // if shift left
        else{
            // "abcdefg" to "defgabc" if shift left by 3
            sum = abs(sum);
            sum %= n;
            res = s.substr(sum, n - sum) + s.substr(0, sum);
        }
        
        return res;
    }
};