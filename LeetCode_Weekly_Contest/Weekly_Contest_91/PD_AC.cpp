class Solution {
public:
    int shortestSubarray(vector<int>& arr, int target) {
        int prefix_sum[arr.size() + 1] = {0};

        for(int i = 1; i <= arr.size(); i++)
        {
            prefix_sum[i] = prefix_sum[i - 1] + arr[i - 1];
        }

        int ans = -1;

        deque<int> window_left;

        for(size_t end = 0; end <= arr.size(); end++)
        {
            while(!window_left.empty() && prefix_sum[end] - prefix_sum[window_left.back()] <= 0)
            {
                window_left.pop_back();
            }
            while(!window_left.empty() && prefix_sum[end] - prefix_sum[window_left.front()] >= target)
            {
                int beg = window_left.front();
                window_left.pop_front();

                if(ans == -1)
                {
                    ans = end - beg;
                }
                else
                {
                    ans = min(ans, (int)end - beg);
                }
            }
            window_left.push_back(end);
        }

        return ans;

    }
};
