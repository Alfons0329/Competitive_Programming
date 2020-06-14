class Solution
{
public:
    bool isMonotonic(vector<int>& A)
    {
        bool up = 0, dn = 0;
        int n = A.size();
        for(int i = 0; i < n - 1; i++)
        {
            if(A[i] > A[i + 1])
            {
                dn = 1;
            }
            else if(A[i] < A[i + 1])
            {
                up = 1;
            }
        }
        return !(dn & up);
    }
};
