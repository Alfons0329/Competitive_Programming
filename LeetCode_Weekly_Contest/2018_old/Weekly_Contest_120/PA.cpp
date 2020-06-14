class Solution 
{
public:
    vector<int> sortedSquares(vector<int>& A) 
    {
        int n = A.size();
        vector<int> res;
        for(int i = 0; i < n; ++i) 
        {
            A[i] = A[i] * A[i];
            res.push_back(A[i]);
        }
        sort(res.begin(), res.end());
        return res;
    }
};