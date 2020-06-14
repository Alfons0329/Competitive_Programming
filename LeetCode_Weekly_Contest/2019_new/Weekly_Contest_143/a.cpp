class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) 
    {
        vector<int> res(num_people);
        int idx = 0, cnt = 1;
        while(candies)
        {
            res[idx % num_people] += (candies > cnt) ? cnt : candies;
            candies = (candies > cnt) ? candies - cnt : 0;
            cnt++;
            idx++;
        }
        return res;
    }
};
