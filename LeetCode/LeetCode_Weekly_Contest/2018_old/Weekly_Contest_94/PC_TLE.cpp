class Solution
{
public:
    int minEatingSpeed(vector<int>& pls, int hr)
    {
        int mxm = 1e9, minn = 0;
        int zr = 1;
        int tmp_time = 0;
        int flg = 0, flg2 = 0;
        while(1)
        {
            //cnt down from max
            tmp_time = 0;
            if(!flg)
            {
                for(auto &j : pls)
                {
                    tmp_time += ceil((float) ((float)j / (float)mxm));
                }
                mxm--;
            }
            if(tmp_time > hr)
            {
                flg = 1;
            }
            //cnt up from min
            tmp_time = 0;
            if(!flg2)
            {
                for(auto &j : pls)
                {
                    tmp_time += ceil((float) ((float)j / (float)zr));
                }
                zr++;
            }
            if(tmp_time < hr)
            {
                flg2 = 1;
            }
            if(flg && flg2)
            {
                break;
            }
            if(zr >= mxm)
            {
                break;
            }
        }
        return zr > mxm ? mxm + 2 : zr + 2;
    }
};
