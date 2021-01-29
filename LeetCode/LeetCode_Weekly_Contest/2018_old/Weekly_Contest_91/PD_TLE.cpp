/*
TLE in very large testcases(vector with length more than 30000), testcases 83/93
the algorithm is implemented in the sliding-window.
need to optimize to O(N)
*/
class Solutio
{
public:
    int shortestSubarray(vector<int>& arr, int target_val)
    {

        if(arr.size() == 1)
        {
            return 1;
        }
        int start_idx = 0, end_idx = 1, cur_sum = 0;
        unsigned int min_len = 9999999;
        while(arr.size() > 1)
        {
            cur_sum = 0;
            for(int i = start_idx; i <= end_idx; i++)
            {
                cur_sum += arr[i];
            }
            // printf("sum is %d\n", cur_sum);
            if(cur_sum < target_val)
            {
                // printf("end_idx++ since too small\n");
                if(end_idx != arr.size() - 1)//keep adding the elements, extending the right side of the window
                {
                    end_idx++;
                }
                else if(end_idx == arr.size() - 1 && start_idx < end_idx) //shrink the subarray, try to toss away some negative values
                {
                    if(cur_sum - arr[start_idx] >= target_val) //if successfully toss away enough negative value, then the min_len can be updated
                    {
                        // printf("update min len \n");
                        min_len = min((unsigned int)end_idx - start_idx, min_len);
                    }
                    start_idx++; //shrink the left side of the window
                }
            }
            else //if the target value is reached, then we can try to shrink the left side of the window to try to make the window narrower
            {
                //printf("start_idx++ since enough\n");
                //printf("cur_sum %d go third minus %d\n", cur_sum, arr[start_idx]);
                min_len = min((unsigned int)end_idx - start_idx + 1, min_len);
                if(start_idx < end_idx) //shrink the leftside
                {
                    start_idx++;
                }
                else if(start_idx == end_idx) //moving forward to prevent locked situation
                {
                    start_idx++;
                    end_idx++;
                }
                if(cur_sum - arr[start_idx - 1] >= target_val) //update the min value if the shrinked sliding window still satisfies the criteria
                {
                    min_len = min((unsigned int)end_idx - start_idx + 1, min_len);
                }
            }
            //I think the TLE mainly due to this part since my time complexity is not O(N) but O(N^2)
            if(start_idx == arr.size() - 1 && end_idx == arr.size() - 1 ) //if we reach the end of the vector, pop the last element, to do again for the smaller array.
            {
                arr.pop_back();
                start_idx = 0;
                end_idx = 1;
            }
            // printf("start_idx %d, end_idx %d min_len%d\n" ,start_idx, end_idx, min_len);
        }
        return (min_len == 9999999) ? -1 : min_len; //check the return answer
    }
};
