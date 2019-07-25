#define all(x) x.begin(), x.end()
class Solution 
{
public:
    int mctFromLeafValues(vector<int>& arr) 
    {
        int res = 0;
        while(1)
        {
            int n = arr.size();
            if(n <= 1)
            {
                break;
            }
            int min_pos = min_element(all(arr)) - arr.begin();
            
            if(min_pos > 0 && min_pos < n - 1)
            {
                res += min(arr[min_pos + 1], arr[min_pos - 1]) * arr[min_pos];// greedy to find either left is smaller or right
            }
            else if(min_pos == 0)
            {
                res += arr[min_pos] * arr[1];
            }
            else if(min_pos == n - 1)
            { 
                res += arr[min_pos] * arr[n - 2];
            }
            
            if(n)
            {
                arr.erase(arr.begin() + min_pos);
            }
        }
        return res;
    }
};
