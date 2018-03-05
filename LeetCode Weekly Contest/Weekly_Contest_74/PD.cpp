class Solution {
public:
    int preimageSizeFZF(int kin)
    {
        int cnt = 0, factorial = 0, zeros = 0;
        while(1)
        {
            if(factorial%5==0 && factorial)
            {
                zeros+=((int)(log(factorial)/log(5)));
                cout<<" factorial is of five multiple "<<factorial<<" zeros "<<zeros<<endl;
            }
            if(zeros == kin)
            {
                cnt++;
            }
            else if(zeros > kin)
            {
                break;
            }
            factorial++;
            cout<<" factorial "<<factorial<<" zeros "<<zeros<<endl;
        }
        return cnt;
    }
};
