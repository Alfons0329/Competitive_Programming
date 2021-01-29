class Solution
{
public:
    int lenLongestFibSubseq(vector<int>& arr)
    {
        int fir = arr[0], sec = arr[1], thr_expected = 0, res = 0, cur_len;
        unordered_set<int> myset(arr.begin(), arr.end());
        for(int i = 0; i < arr.size() - 2; i++)
        {

            for(int j = i + 1; j < arr.size() - 1; j++)
            {
                if(arr[i] + arr[j] >= arr[j + 1])
                {
                    fir = arr[i];
                    sec = arr[j];
                    thr_expected = arr[i] + arr[j];
                    cur_len = 2;
                    while(myset.find(thr_expected) != myset.end()) //keep going the rest in the array
                    {
                        fir = sec;
                        sec = thr_expected;
                        thr_expected = fir + sec;
                        cur_len++;
                        res = max(cur_len, res);
                    }
                }
            }
        }
        return res == 2 ? 0 : res;
    }
};
