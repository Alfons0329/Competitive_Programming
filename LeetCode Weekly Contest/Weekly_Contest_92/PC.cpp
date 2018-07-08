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
        if(num == 4)
        {
            return 0;
        }
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
        string str = to_string(num), l_str(""), r_str("");
        int full_size = str.size() - 1, half_size = str.size() / 2;
        if(str.size() % 2) //odd length
        {
            for(int i = 0 ;i < half_size; i++)
            {
                l_str += str[i];
                r_str += str[full_size - i];
            }
        }
        else
        {
            for(int i = 0 ;i < half_size; i++)
            {
                l_str += str[i];
                r_str += str[full_size - i];
            }
        }
        if((l_str.size() == 1 && r_str.size() == 0) || (l_str.size() == 0 && r_str.size() == 1))
        {
            return 1;
        }
        return l_str == r_str;
    }
};
