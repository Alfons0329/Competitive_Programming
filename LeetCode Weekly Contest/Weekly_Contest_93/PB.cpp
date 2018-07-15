#define pb push_back
class Solution
{
public:
    bool reorderedPowerOf2(int num)
    {
        if(num >= 1 && num <=10)
        {
            if(is_pow2(num))
            {
                return true;
            }
            return false;
        }
        else if(is_pow2(num)) //original order
        {
            return true;
        }
        vector<int> dgt;
        while(num)
        {
            dgt.pb(num % 10);
            num /= 10;
        }
        sort(dgt.begin(), dgt.end());
        int sz = dgt.size(), judge = 0;
        string str;

        do {
            str = "";
            for(int i = 0; i < sz; i++)
            {
                str += (dgt[i] + '0');
            }
            cout << str <<endl;
            judge = atoi(str.c_str());
            if(is_pow2(judge))
            {
                return true;
            }
        }while(next_permutation(dgt.begin(), dgt.end()));
        return false;
    }
    bool is_pow2(int num)
    {
        if((num & (num - 1)) == 0 )
        {
            return true;
        }
        return false;
    }
};
