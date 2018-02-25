#define FORI(n) for(int i = 0; i < n; ++ i)
class Solution
{
public:
    int rotatedDigits(int num)
    {
        string str;
        int cnt=0;
        bool not_good = true;
        for(int i=1;i<=num;i++)
        {
            str = to_string(i);
            cout<<str<<endl;
            not_good = true;
            for(int j=0;j<str.size();j++)
            {
                if(str[j]=='2'||str[j]=='5'||str[j]=='6'||str[j]=='9')
                {
                    not_good = false;
                }
                else if(str[j]=='3'||str[j]=='4'||str[j]=='7')
                {
                    not_good = true;
                    break;
                }
            }
            if(!not_good)
            {
                cnt++;
            }
        }
        return cnt;
    }
};
