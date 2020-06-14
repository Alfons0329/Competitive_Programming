class Solution {
public:
    int preimageSizeFZF(int kin)
    {
        int cnt = 0, factorial = 0, zeros = 0, current_pow = 25;
        while(1)
        {
            if(factorial ==  current_pow * 5)
            {
                cout<<" factorial is now "<<factorial<<" current_pow is now "<<current_pow<<endl;
                current_pow *= 5;
            }
            if(factorial % current_pow == 0 && factorial)
            {
                zeros += ((int)(log(factorial) / log(5)));
                cout<<" factorial is of 25 multiple "<<factorial<<" zeros "<<zeros <<" add "<<((int)(log(factorial) / log(5)))<<endl;
            }
            else if(factorial % 5 ==0 && factorial)
            {
                cout<<" factorial not 25 "<<factorial<<endl;
                zeros++;
            }

            if(zeros == kin)
            {
                cnt++;
            }
            else if(zeros > kin)
            {
                break;
            }
            cout<<" factorial "<<factorial<<" zeros "<<zeros<<endl;
            factorial++;
        }
        return cnt;
    }
    //compare 2 casting, one is the original integer value of log and the other is the double type log, if they are equal of each other
    //in double precision
    //then this is correct one
    bool is_powoffive(int real, int base)
    {
        int integer = (int)(log(real)/log(base));
        double precised = (log(real)/log(base));
        return integer == precised;
    }
};
