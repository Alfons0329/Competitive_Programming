class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int shift_bits = 0;
        while(m != n){
            m >>=1;
            n >>=1;
            shift_bits++;

        }
        return m <<= shift_bits;
    }
};
