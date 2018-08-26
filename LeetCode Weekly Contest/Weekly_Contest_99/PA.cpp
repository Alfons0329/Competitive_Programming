class Solution
{
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B)
    {
        int suma, sumb, flg;
        suma = sumb = 0;
        flg = 0;
        vector<int> res;
        for(int i = 0; i < A.size(); i++)
        {
            suma += A[i];
        }
        for(int i = 0; i < B.size(); i++)
        {
            sumb += B[i];
        }
        int fair = (suma + sumb) / 2;
        for(int i = 0; i < A.size(); i++)
        {
            for(int j = 0; j < B.size(); j++)
            {
                if(suma - A[i] + B[j] == sumb - B[j] + A[i])
                {
                    res.push_back(A[i]);
                    res.push_back(B[j]);
                    flg = 1;
                    break;
                }
            }
            if(flg)
            {
                break;
            }
        }
        return res;
    }
    bool check(vector<int>& A, vector<int>& B)
    {
        int suma, sumb;
        suma = sumb = 0;
        for(int i = 0; i < A.size(); i++)
        {
            suma += A[i];
        }
        for(int i = 0; i < B.size(); i++)
        {
            sumb += B[i];
        }
        //printf("suma %d, sumb %d \n", suma, sumb);
        return (suma == sumb) && (suma) && (sumb);
    }
};
