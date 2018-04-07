#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void check_swap_bubble_sort(vector<int>& arr)
{
    int swap_cnt = 0;
    for(int upper_bound = arr.size() - 1; upper_bound >= 1; upper_bound--)
    {
        for(int j = 0; j < upper_bound; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swap_cnt++;
            }
        }
    }
    printf("Array is sorted in %d swaps.\n",swap_cnt);
    printf("First Element: %d\n",arr[0]);
    printf("Last Element: %d\n",arr.back());
}
int main()
{
   int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++)
    {
       cin >> a[a_i];
    }
    check_swap_bubble_sort(a);
    return 0;
}
