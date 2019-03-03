class Solution 
{
    public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        int n = nums.size();
        int m = 1 << n, cnt = 0, i = 0;
        vector<vector <int> > res(0, vector<int>());
        vector<int> tmp;
        while(--m)
        {
            cnt = 0;
            i = m;
            while(i > 0)
            {
                if(i & 1)
                {
                    tmp.push_back(nums[nums.size() - cnt - 1]);
                }
                cnt++;
                i >>= 1; //shift right to check the next occurance
            }
            res.push_back(tmp);
            tmp.clear();
        }
        tmp.clear();
        res.push_back(tmp);//including the empty one
        return res;
    }
};