#define FORI(n) for(int i = 0; i < n; ++ i)
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr)
    {
        int max_value=0,cnt=0;
        //O(n^2) solution`
        FORI(arr.size())
        {
            max_value = max(max_value,arr[i]);
            if(max_value==i)
                cnt++;
        }
        return cnt;
    }
};
