class Solution 
{
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        int n = stones.size();
        while(true)
        {
            sort(stones.begin(), stones.end());
            n = stones.size();
            
            if(n <= 1)
            {
                break;
            }
            
            int a = stones[n - 1];
            int b = stones[n - 2];
            
            int x = min(a, b);
            int y = max(a, b);
            
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
