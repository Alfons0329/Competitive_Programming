class Solution {
public:
    int findComplement(int num) {
        vector<int> v; // bin representation of num
        if(!num){
            return 1;
        }
        // get bin representation of num
        while(num){
            v.emplace_back(num & 1); // get parity of that bit
            num >>= 1;
        }
        int res = 0;
        for(int i = 0; i < v.size(); i++){
            res += ((v[i] ^ 1) << i);
        }
        return res;
    }
};
