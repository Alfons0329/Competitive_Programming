class Solution
{
public:
    bool stoneGame(vector<int>& piles)
    {
        int num = 0;
        for(int i = 0;i < piles.size(); i++)
        {
            num ^= piles[i];
        }
        return num % 2 == 1;
    }
};
