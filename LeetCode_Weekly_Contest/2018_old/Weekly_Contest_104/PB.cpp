class Solution 
{
public:
    int partitionDisjoint(vector<int>& A) 
    {
        int n = A.size();
        
        int pivot = n - 1;
        int res = n;
        int rmin = INT_MAX, lmax = A[0];
        int maxton[n - 1] = {0};
        
        for(int j = 0; j < n - 1; j++)
        {
            lmax = max(lmax, A[j]);
            maxton[j] = lmax;
        }
        
        while(pivot > 0)
        {
            rmin = min(rmin, A[pivot]);
            lmax = maxton[pivot - 1];
            if(lmax <= rmin)
            {
                res = pivot;
            }
            pivot--;
        }
        return res == 0 ? 1 : res;
    }
};