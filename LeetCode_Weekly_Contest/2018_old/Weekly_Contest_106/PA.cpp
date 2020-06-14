class Solution 
{
public:
    vector<int> sortArrayByParityII(vector<int>& A) 
    {
        int n = A.size();
        
        int odd[n]={0};
        int even[n]={0};
        int optr = 0, eptr = 0;
        for(int i = 0; i < n; i++)
        {
            if(A[i] & 1) 
            {
                odd[optr++] = A[i];
            }
            else
            {
                even[eptr++] = A[i];
            }
        }
        
        optr = 0, eptr = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(i & 1)
            {
                A[i] = odd[optr++];
            }
            else
            {
                A[i] = even[eptr++];
            }
        }
        
        return A;
    }
};