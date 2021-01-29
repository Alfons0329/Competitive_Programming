class Solution {
public:
    int nthUglyNumber(int n) {
        int two = 0, three = 0, five = 0, next = 0;
        vector<int> res(1, 1);
        n -= 1;
        while(n--){
            next = min(res[two] * 2, min(res[three] * 3, res[five] * 5));
            if(next == res[two] * 2){
                two++;
            }
            if(next == res[three] * 3){
                three++;
            }
            if(next == res[five] * 5){
                five++;
            }
            res.push_back(next);
        }
        
        return res.back();
    }
};
