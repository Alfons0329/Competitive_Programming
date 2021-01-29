class Solution 
{
public:
    int totalFruit(vector<int>& tree) 
    {
        int n = tree.size(), res = 0;
        if(tree.size() == 1 || tree.size() == 2)
        {
            return tree.size();
        }
        unordered_map<int, int> type;
        
        int left = 0, right = 0; //sliding window left and right
        for(int right = 0; right < n; right++)
        {
            type[tree[right]]++;
            if(type.size() >= 3) //more than two due to current element tree[i], than the previous element is the last position with only two types of fruit
            {
                while(type.size() >= 3) //move to new pos
                {
                    type[tree[left]]--;
                    if(type[tree[left]] == 0)
                    {
                        type.erase(tree[left]);
                    }
                    left++;
                }
                // printf("  after left %d, right %d, cnt %d \n", left, right, cnt);
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};