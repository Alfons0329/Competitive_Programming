class Solution 
{
    public:
        static bool cmp(int a, int b)
        {
            return a <= b;
        }
        int heightChecker(vector<int>& heights) 
        {
            int n = heights.size(), res = 0;
            vector<int> h2 = heights;
            sort(h2.begin(), h2.end());

            for(int i = 0; i < n; i++)
            {
                if(heights[i] != h2[i])
                {
                    res++;
                }
            }
            return res;
        }
};
