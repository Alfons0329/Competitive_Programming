//algorithm and source credit to : https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/discuss/117612/C++-O(n)-solution-with-explanations

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R)
    {
        int res = 0, heads = 0, tails = 0;
        for (int val : A)
        {
            if (L <= val && val <= R)
            {
                //如果找到一個符合區間的數值，則之前身為tail的，全部可以被提拔為head，在加上自己本身新找到的數字，因此head += tails + 1
                //而res變可以新增那個長度
                heads+= tails + 1;
                tails = 0;
                res += heads;
            }
            else if (val < L)
            {
                //小於L的數字可以作為區間數列延伸的尾部， 因此陣列又在延長方才的head數目
                //舉例：L=32 R=69 今已經iterate，[55 36] 已經有三個了 在多一個5後，便可有[55] [36] [55,36] [55 36 55] [36 55]
                //因為自己不算在LR區間 因此只能　+= heads 而不需要再加一
                tails++;
                res += heads;
            }
            else
            {
                heads = 0;
                tails = 0;
            }
        }
        return res;
    }
};
