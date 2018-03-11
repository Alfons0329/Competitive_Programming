class Solution {
public:
    int bestRotation(vector<int>& arr)
    {
        int maxm=0, sc=0, cnt=0, k_val=0;
        int up_bnd = arr.size();
        while(up_bnd--)
        {
            int tmp=arr[arr.size()-1];
            aarr.resize(arr.size()-1)
            for(int i=0;i<arr.size()-1;i++)
            {
                arr[i] = arr[i+1];
            }
            arr.pb(tmp);
            if(sc>maxm)
            {
                maxm=sc;
                k_val=cnt;
            }
            cnt++;
        }
        return k_val;
    }
};
