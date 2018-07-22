//binary search
class Solution
{
public:
    int minEatingSpeed(vector<int>& pls, int hr)
    {
        int mxm = 1e9, minn = 1, mid = 0, ans = 1e9;
        while(minn < mxm)
        {
            int tmp_time = 0; //count the time for current eating speed K
            mid = (mxm + minn) / 2;
            for(auto &j : pls)
            {
                tmp_time += ceil(((float)j / (float)mid));
            }
            if(tmp_time > hr) //cannot finish before guard back, should eat faster
            {
                minn = mid + 1;
            }
            else //can finish before guard back, may eat slower
            {
                mxm = mid;
                ans = min(ans, mid);
            }
        }
        return ans;
    }
};
