class Solution
{
public:
    int bitcnt(int num)
    {
        int cnt = 0;
        while(num > 0)
        {
            if(num & 0x1)
            {
                cnt++;
            }
            num>>=1;
        }
        return cnt;
    }
    bool is_prime(int num)
    {
        if(num == 1)
            return false;

        for(int i=2;i<=(int)sqrt(num);i++)
        {
            if(num % i == 0)
            {
                return false;
            }
        }
        return true;
    }
    int countPrimeSetBits(int left, int right)
    {
        int cnt = 0, bit = 0;
        for (size_t i = left; i <= right; i++)
        {
            bit = bitcnt(i);
            if(is_prime(bit))
            {
                cnt++;
            }
        }
        return cnt;
    }
};
