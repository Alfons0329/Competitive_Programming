#define FORI(n) for(int i = 0; i < n; ++ i)
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B)
    {
        int aend,bend
        FORI(A.size()-1)
        {
            if(A[i]>=A[i+1])
            {
                aend = i+1;
            }
        }
        FORI(B.size()-1)
        {
            if(B[i]>=B[i+1])
            {
                bend = i+1;
            }
        }
        int minst = min(aend,bend);
        for(i=minst;i<A.size();i++)
        {
            
        }

    }
};
