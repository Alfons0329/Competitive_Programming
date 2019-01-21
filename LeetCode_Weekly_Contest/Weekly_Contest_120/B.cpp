class Solution 
{
public:
    int maxTurbulenceSize(vector<int>& A) 
    {
        int n = A.size();
        if(n == 1)
        {
            return 1;
        }
        int cnt = 0, tmp = 0, res = 0;
        for(int i = 0; i < n - 1; i++)
        {
            tmp = 0;
            if(A[i] < A[i + 1])
            {
                cnt = 1;
            }
            else if(A[i] > A[i + 1])
            {
                cnt = 0;
            }
            for(int j = i; j < n - 1; j++)
            {
                if(cnt) // <
                {
                    if(A[j] < A[j +1])
                    {
                        tmp++;
                        cnt ^= 1;
                    }
                    else
                    {
                        break;
                    }
                }
                else // >
                {
                    if(A[j] > A[j +1])
                    {
                        tmp++;
                        cnt ^= 1;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            res = max(res, tmp);
        }
        return res + 1;
    }
};
