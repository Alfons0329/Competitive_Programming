class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2)
    {
        int idx_sum=0;

        vector<string> res;

        bool flag=0;
        for(int i=0;i<list1.size();i++)
        {
            for(int j=0;j<list2.size();j++)
            {
                if(list1[i]==list2[j]&&!flag)
                {
                    idx_sum=i+j;
                    flag=1;
                    res.push_back(list1[i]);
                    break;
                }
                else if(list1[i]==list2[j]&&flag)
                {
                    if(i+j<=idx_sum)
                    {
                        idx_sum=i+j;
                        res.push_back(list1[i]);
                        break;
                    }
                }
            }
        }
        return res;
    }
};
