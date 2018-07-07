/*
for a fixed left, we want to find the smallest right such that arr[right + 1] - arr[left] >= target_val
*/
class Solution
{
public:
    int shortestSubarray(vector<int>& arr, int target_val)
    {
        if(arr.size() == 1)
        {
            return 1;
        }
        int prefix_sum[arr.size() + 1] = {0}, interval_sum = 0;  //interval_sum = arr[right + 1] - arr[left]
        for(int i = 0; i < arr.size(); i++)
        {
            prefix_sum[i + 1] += prefix_sum[i] + arr[i];
        }
        for(int i = 0; i < arr.size() + 1; i++)
        {
            printf("prefix to %d prefix_sum is %d\n", i, prefix_sum[i]);
        }
        int left = 0, right = 1;
        for()
        return 0;
    }
};
