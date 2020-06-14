class Solution 
{
public:
    vector<int> sortArrayByParity(vector<int>& A) 
    {
        vector<int> res;
        int n = A.size();
        for(int i = 0; i < n ;i++)
        {
            if((A[i]) % 2 == 0) //even
            {
                res.push_back(A[i]);
            }
        }
        for(int i = 0; i < n ;i++)
        {
            if((A[i]) & 1) //odd
            {
                res.push_back(A[i]);
            }
        }
        return res;
        
    }
};