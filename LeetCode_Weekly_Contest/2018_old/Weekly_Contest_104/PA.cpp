class Solution 
{
public:
    bool hasGroupsSizeX(vector<int>& deck) 
    {
        unordered_map<int, int> my;
        int n = deck.size();
        for(int i = 0; i < n ; i++)
        {
            my[deck[i]]++;
        }
        int minn = INT_MAX;
        for(unordered_map<int, int>::iterator it = my.begin(); it != my.end(); it++)
        {
            minn = min(minn, it->second);
        }
        
        for(unordered_map<int, int>::iterator it = my.begin(); it != my.end(); it++)
        {
            for(unordered_map<int, int>::iterator it2 =it; it2 != my.end(); it2++)
            {
                if(__gcd(it->second, it2->second) == 1)
                {
                    return false;
                }
            }
        }
        return true;
    }
};