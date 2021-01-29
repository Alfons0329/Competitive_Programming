class Solution
{
public:
    vector<int> transformArray(vector<int> &arr)
    {
        int chk = 1, n = arr.size();
        vector<int> res(n, 0);
        if (n < 3)
        {
            return arr;
        }

        res = arr;
        while (1)
        {
            chk = 0;
            for (int i = 1; i < n - 1; i++)
            {
                if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
                {
                    res[i] = arr[i] - 1;
                    chk = 1;
                }
                else if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1])
                {
                    res[i] = arr[i] + 1;
                    chk = 1;
                }
            }

            if (chk == 0)
            {
                break;
            }
            arr = res; // important
        }
        return res;
    }
}