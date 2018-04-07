#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
/*
Maybe the insert method is good, ruh through the place where good for the place for the next element
*/
vector<int> arr;

void print_arr()
{
    printf("\n--------------\n");
    for(int i = 0; i < arr.size(); i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n--------------\n");
}

void calculate(int insert_val)
{
    if(arr.size() == 0)
    {
        arr.push_back(insert_val);
        printf("%lf\n",(float)arr[0]);
    }
    else if(arr.size() == 1)
    {
        arr.push_back(insert_val);
        sort(arr.begin(), arr.end());
        printf("%lf\n",(arr[0] + arr[1]) / 2.0f);
    }
    else
    {
        vector<int>::iterator it = arr.begin();
        if(insert_val < arr[0])
        {
            arr.insert(it, insert_val);
        }
        else if(insert_val > arr.back())
        {
            arr.push_back(insert_val);
        }
        else
        {
            for(int i = 0, j = arr.size() - 2; i < arr.size() / 2 || j >= arr.size() / 2; i++, j--) //binary search both side, parallel processing
            {
                if(arr[i] < insert_val && insert_val < arr[i + 1])
                {
                    arr.insert(it + i + 1, insert_val);
                    break;
                }
                else if(arr[j] < insert_val && insert_val < arr[j + 1])
                {
                    arr.insert(it + j + 1, insert_val);
                    break;
                }
            }
        }
        if(arr.size() % 2 == 0)
        {
            printf("%lf\n",(arr[arr.size() / 2]+ arr[arr.size() / 2 - 1])/2.0f);
        }
        else
        {
            printf("%lf\n",(float)arr[arr.size() / 2.0f]);
        }
    }
    print_arr();
}
int main()
{
    int n, tmp;
    cin >> n;
    arr.resize(0);
    for(int a_i = 0;a_i < n;a_i++)
    {
        cin>>tmp;
        calculate(tmp);
    }
    return 0;
}
