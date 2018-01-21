//611. Valid Triangle Number
class Solution {
public:
    int triangleNumber(vector<int>& nums)
    {
        sort(nums.begin(),nums.end()); //sort the vector first
        //triangle inequality for doing abs(a-b)<c<a+b
        //先枚舉a b 接著找到c的範圍　要記得從index K往後找因為這樣不會有重複，往前找會有
        vector<bool>used(nums.size(),0);
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i==nums.size()-2)
                break;
            for(int j=i+1;j<nums.size();j++)
            {
                for(int k=j+1;k<nums.size();k++)
                {
                    //printf("i %d j %d k%d\n",i,j,k);
                    if(((abs(nums[i]-nums[j]))<nums[k])&&(nums[k]<(nums[i]+nums[j])))
                    {
                        cnt++;
                        //printf("k is now %d and cnt is now %d\n",k,cnt);
                    }
                }
            }
        }
        return cnt;
    }
};
