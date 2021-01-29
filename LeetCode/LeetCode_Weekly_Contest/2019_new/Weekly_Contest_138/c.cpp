class Solution {
    public:
        bool check(vector<int>& A)
        {
            int n = A.size();
            for(int i = 0; i < n - 1; i++)
            {
                if(A[i] > A[i + 1])
                {
                    return false;
                }
            }
            return true;
        }

        vector<int> prevPermOpt1(vector<int>& A) 
        {
            if(check(A))
            {
                return A;
            }

            int n = A.size(), pos = 0, maxval = 0;

            for(int i = 0; i < n - 1; i++)
            {
                if(A[i] > A[i + 1])
                {
                    pos = i;
                }
            }

            int swappos = 0, smallese = INT_MAX;
            for(int i = pos + 1; i < n; i++)
            {
                if(A[i] < A[pos] && A[i] != A[i - 1])
                {
                    swappos = i;
                }
                else
                {
                    break;
                }
            }
            swap(A[pos], A[swappos]);
            return A;
        }
};
