#define FORI(n) for(int i = 0; i < n; ++ i)
#include <cstdlib>
class Solution
{
public:
    int cti(char c)
    {
        if ( '0'<=c && c<='9' ) return c-'0';
        else return 10+c-'a';
    }
    char itc(int i)
    {
        if (0<=i && i<=9) return '0'+i;
        else return 'a'+i-10;
    }
    string similarRGB(string color)
    {
        int dist = 0, best = 99999999;
        int original = 0;
        color = color.substr(1,6);
        stringstream ss;
        ss<<hex<<color;
        ss>>original;

        int R,G,B,nr,ng,nb,nr1,ng1,nb1;
        string sr,sg,sb;

        R=original & 0xff0000;
        G=original & 0xff00;
        B=original & 0xff;
        R>>=16;
        G>>=8;

        //find smallest R
        for(int i = 0;i < 16;i++)
        {
            nr = i<<4 | i;
            if(abs(nr-R)<best)
            {
                sr="";
                best = abs(nr-R);
                nr = i;
                sr += itc(i);
            }
        }
        //fins smallest G
        best = 99999999;
        for(int i = 0;i < 16;i++)
        {
            ng = i<<4 | i;
            if(abs(ng-G)<best)
            {
                sg="";
                best = abs(ng-G);
                ng = i;
                sg += itc(i);
            }
        }
        //find smallest B
        best = 99999999;
        for(int i = 0;i < 16;i++)
        {
            nb = i<<4 | i;
            if(abs(nb-B)<best)
            {
                sb="";
                best = abs(nb-B);
                nb = i;
                sb += itc(i);
            }
        }

        return "#"+sr+sr+sg+sg+sb+sb;
    }
};
