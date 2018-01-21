#define FORI(n) for(int i = 0; i < n; i++)
#define ULL unsigned int
class Solution {
public:
    //Hint: add a chunk if left max is <= right min
    int maxChunksToSorted(vector<int>& arr)
    {
        int cnt=0;
        int lmax=0, rmin=999999999;
        FORI(arr.size()-1)
        {
            int lmax=arr[i], rmin=arr[i+1];
            {
                for(int j=0;j<=i;j++)
                {
                    lmax=max(lmax, arr[j]);
                }
                for(int j=i+1;j<arr.size();j++)
                {
                    rmin=min(rmin, arr[j]);
                }
                if(lmax<=rmin)
                {
                    cnt++;
                }
                cout<<"Lmax "<<lmax<<" Rmin "<<rmin<<endl;
            }
        }
        cout<<cnt+1<<endl;
        return cnt+1;
    }
};
