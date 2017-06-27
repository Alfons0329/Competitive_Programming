class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n)
    {
        int cnt=0;
        if(flowerbed.size()>1)
        {
            for(int i=0;i<flowerbed.size();i++)
            {
                if(flowerbed[i]==0)
                {
                    if(i==0&&flowerbed[1]==0)//check left border
                    {
                        cnt++;
                        flowerbed[i]=1;
                    }
                    else if(i==flowerbed.size()-1&&flowerbed[flowerbed.size()-2]==0)//check right border
                    {
                        cnt++;
                        flowerbed[i]=1;
                    }
                    else if(flowerbed[i-1]==0&&flowerbed[i+1]==0)
                    {
                        cnt++;
                        flowerbed[i]=1;
                    }
                }
            }
            return (n<=cnt)?1:0;
        }
        else if(flowerbed[0]==1&&n==0) //special testcase
        {
            return 1;
        }
        else if(flowerbed[0]==0&&n<=1) //special testcase
        {
            return 1;
        }

            return 0;  //default

    }
};
