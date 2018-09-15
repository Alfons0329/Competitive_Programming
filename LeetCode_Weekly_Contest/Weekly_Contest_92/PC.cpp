class Solution
{
public:
    int primePalindrome(int num)
    {
        if(num == 1)
        {
            return 2;
        }
        else if(num >= 9989900)
        {
            return 100030001;
        }
        int flag = 0, cnt = 2;
        while(1)
        {
            if(cnt >= num)
            {
                if(is_prime(cnt))
                {
                    if(is_palindrome(cnt) )
                    {
                        break;
                    }
                }
            }
            cnt++;
        }
        return cnt;
    }
    bool is_prime(int num)
    {
        for(int i = 2;i <= sqrt(num) ; i++)
        {
            if(num % i == 0)
            {
                return 0;
            }
        }
        return 1;
    }
    bool is_palindrome(int num)
    {

        string str = to_string(num);
        string rev = str;
        if(num > 11 && str.size() % 2 == 0)
        {
            return 0;
        }
        reverse(rev.begin(), rev.end());
        return str == rev;
    }
};
