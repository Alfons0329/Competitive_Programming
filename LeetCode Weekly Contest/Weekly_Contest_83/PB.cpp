class Solution
{
public:
    string maskPII(string str)
    {
        string res = "";
        string name, dom;
        string unmask;
        int mail = str.find("@");
        if(mail != string::npos) //email type
        {
            cout <<"str0 "<<tolower(str[0])<<endl;
            name = "*******";
            name[0] = tolower(str[0]);
            name[6] = tolower(str[mail - 1]);
            for(int i = mail; i < str.size(); ++i)
            {
                dom += tolower(str[i]);
            }
            cout << "name "<<name <<" dom "<< dom <<endl;
            res = name + dom;
        }
        else
        {
            int cnt;
            for(int i = str.size() - 1; i >= 0; --i)
            {
                if(cnt >= 4)
                {
                    break;
                }
                if(str[i] >= '0' && str[i] <= '9')
                {
                    unmask += str[i];
                    ++cnt;
                }
            }
            printf("unmask %s\n", unmask.c_str());
            reverse(unmask.begin(), unmask.end());
            int cy = str.find("+"), cy_len = 0, dgt_cnt = 0;
            string country = "";
            for(int i = 0; i < str.size(); ++i)
            {
                if(isdigit(str[i]))
                {
                    ++dgt_cnt;
                }
            }
            if(dgt_cnt > 10)
            {
                for(int i = 0; i < str.size(); ++i)
                {
                    if(str[i] != '-')
                    {
                        ++cy_len;
                    }
                    else
                    {
                        break;
                    }
                }
                for(int i = 0; i < dgt_cnt - 10; ++i)
                {
                    country+="*";
                }
                printf("cy_len %d\n", cy_len);
                if(country.size() > 3)
                {
                    country = "***";
                }
                res = "+" + country + "-***-***-" + unmask;
            }
            else
            {
                res = "***-***-" + unmask;
            }
        }
        return res;
    }
};
