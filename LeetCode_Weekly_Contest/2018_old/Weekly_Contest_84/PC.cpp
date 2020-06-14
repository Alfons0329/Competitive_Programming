class Solution
{
public:
    int consecutiveNumbersSum(long int N)
    {
        long int count = 0;
        for ( long int start = 1; start * (start + 1) < 2 * N; start++)
        {
            float a = (1.0 * N-(start * (start + 1)) / 2) / (start + 1);
            if (a-(long int)a == 0.0)
                count++;
        }
        return (int) count;
    }
};
