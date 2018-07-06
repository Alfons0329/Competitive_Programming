class Solution
{
public:
    struct col_data
    {
        int col_0, col_1;
    }; //store the data of 1, 0 of each column
    int matrixScore(vector<vector<int>>& arr)
    {
        int flag_1 = 0, flag_2 = 0, cnt_0 = 0, cnt_1 = 0;
        while(1)
        {
            //data structure
            vector<col_data>col_data_vec;
            col_data_vec.clear();
            col_data_vec.resize(arr[0].size());
            flag_1 = 1;
            flag_2 = 1;
            //statistical data of 1 and 0 of each column
            cout << "part 1" <<endl;
            for(int i = 0; i < arr[0].size(); i++)
            {
                cnt_0 = cnt_1 = 0;

                for(int j = 0; j < arr.size(); j++)
                {
                    cout << " i " << i << " j " <<j <<endl;
                    if(arr[i][j])
                    {
                        cnt_1++;
                    }
                    else
                    {
                        cnt_0++;
                    }
                }
                if(cnt_0 > cnt_1)
                {
                    flag_1 = 0;
                }
                col_data_vec[i].col_0 = cnt_0;
                cout << "fai;l" << endl;
                col_data_vec[i].col_1 = cnt_1;
            }

            cout << "part 2" <<endl;
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
            cout << "part 3" <<endl;
            for(int i = 0; i < col_data_vec.size(); i++)
            {
                if(col_data_vec[i].col_0 > col_data_vec[i].col_1)
                {
                    for(int j = 0; j < arr.size(); j++)
                    {
                        arr[i][j] ^= 1;
                    }
                }
            }

            //toggle the row if such row's arr[0][col] = 0, if so, toggle the whole row
            cout << "part 4" <<endl;
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
