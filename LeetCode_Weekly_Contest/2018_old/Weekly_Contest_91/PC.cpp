/*
Algorithm design:
Greedy algorithm is used in this problem.
Since 2^n > sum(2^n-1 + 2^n-2 + ....... + 1), so the msb(most significant bit) has more power than all the other.
Steps:
1. We may toggle the whole column if cnt_0 is greater than cnt_1 in such row to make # of 1s more than 0s.
2. Than we toggle the whole row if the first
3. For loop termination,  we check 2 flags
    First we check if all of the columns that 1s are greater than 0s.
    Than we check if all of the rows that the msb is all 1 to max the value.
*/
class Solution
{
public:
    int matrixScore(vector<vector<int>>& arr)
    {
        int flag_1 = 0, flag_2 = 0, cnt_0 = 0, cnt_1 = 0;
        vector<pair<int, int>>col_data_pair;
        while(1)
        {
            //data structure
            col_data_pair.clear();
            col_data_pair.resize(arr[0].size());
            flag_1 = 1;
            flag_2 = 1;
            //statistical data of 1 and 0 of each column
            for(int i = 0; i < arr[0].size(); i++)
            {
                cnt_0 = cnt_1 = 0;

                for(int j = 0; j < arr.size(); j++)
                {
                    if(arr[j][i])
                    {
                        cnt_1++;
                    }
                    else
                    {
                        cnt_0++;
                    }
                }
                //check the first flag of 1s and 0s
                if(cnt_0 > cnt_1)
                {
                    flag_1 = 0;
                }

                col_data_pair[i].first = cnt_0;
                col_data_pair[i].second = cnt_1;
            }
            //check the second flag of MSB
            for(int i = 0; i < arr.size(); i++)
            {
                if(arr[i][0] == 0)
                {
                    flag_2 = 0;
                }
            }
            if(flag_1 == 1 && flag_2 == 1)
            {
                break;
            }
            //toggle the column if such column's 0 more than 1

            for(int i = 0; i < col_data_pair.size(); i++)
            {
                if(col_data_pair[i].first > col_data_pair[i].second)
                {
                    for(int j = 0; j < arr.size(); j++)
                    {
                        arr[j][i] ^= 1;
                    }
                }
            }

            //toggle the row if such row's arr[0][col] = 0, if so, toggle the whole row

            for(int i = 0; i < arr.size(); i++)
            {
                if(arr[i][0] == 0)
                {
                    for(int j = 0; j < arr[i].size(); j++)
                    {
                        arr[i][j] ^= 1;
                    }
                }
            }


        }
        return binary_sum(arr);
    }
    int binary_sum(vector<vector<int>>& arr)
    {
        unsigned int sum = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            string str_bin("");
            for(int j = 0; j < arr[i].size(); j++)
            {
                str_bin += arr[i][j] + '0';
            }
            sum += (unsigned int) stoi(str_bin, nullptr, 2);
        }
        return sum;
    }
};
