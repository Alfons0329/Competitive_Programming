class Solution 
{
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        while(true)
        {
            sort(stones.begin(), stones.end());
            int n = stones.size();

            if(n <= 1)
            {
                break;
            }
            
            int y = stones[n - 1];
            int x = stones[n - 2];
            
            stones.pop_back();
            stones.pop_back();

            if(x != y)
            {
                stones.push_back(y - x);
            }
        }
        return stones.size() ? stones[0] : 0;
    }
};
