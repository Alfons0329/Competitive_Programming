class Solution {
    public:
        bool isPerfectSquare(int num) {
            long long l = 0, r = num;
            while(l <= r){
                long long m = l + ((r - l) >> 1);
                long long sqm = m * m;
                if(sqm > num){
                    r = m - 1;
                }
                else if(sqm < num){
                    l = m + 1;
                }
                else{
                    return true;
                }
            }
            return false;
        }
}
