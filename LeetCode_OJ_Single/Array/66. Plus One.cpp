class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        digits.insert(digits.begin(), 0);
        
        for(int i = n; i >= 1; i--){
            if(i == n){
                digits[i] += 1;
            }
            if(digits[i] >= 10){
                digits[i - 1] += (digits[i] / 10);
                digits[i] -= 10;
            }
        }
        
        auto it = digits.begin();
        it++;
        if(digits[0] == 0){
            vector<int> res(it, digits.end());
            return res;
        }
        else{
            return digits;
        }
    }
};