#define FORI(n) for(int i = 0; i < n; ++ i)
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B)
    {
        int sz = A.size();
        vector<int> swap(sz, INT_MAX),unswap(sz, INT_MAX);
        //calculating the step of swapped or not till this place.
        unswap[0] = 0;
        swap[0] = 1;

        for(int i = 1;i < sz;i++)
        {
            if(A[i - 1] < A[i] && B[i - 1] < B[i]) //如果兩方都依然符合遞增，則可以一次換兩個column或是都不要換，因為之前的已經符合嚴格遞增
            //推理過來必定也會繼續嚴格遞增，否則就會被替換了
            {
                unswap[i] = min(unswap[i - 1], unswap[i]);
                //如果不要替換，就是依然維持跟上一次一樣的未替換數字（這一次是intmax 所以一定會取到較小的）


                swap[i] = min(swap[i - 1] + 1, swap[i]);
                //如果要替換，那麼先前累積的替換次數到這裡就會再多一次，因為現在多的i又要再換一次了。
            }

            if(A[i - 1] < B[i] && B[i - 1] < A[i]) //若是這種交叉符合形，則i或是i-1位置可以允許有一個要被替換，因為兩個都換的話效果等於沒有換
            {
                unswap[i] = min(unswap[i], swap[i - 1]);
                //如果不要替換這一個，那麼先前的勢必都要符合嚴格遞增的形式，而一路依據單一替換換過來



                swap[i] = min(unswap[i - 1] + 1, swap[i]);
                //如果要替換，因為如果只換這一個就能讓整個數列符合要求，那麼代表先前的都沒有必要換，直接從這一個位置開始換，所以swap重新計算，從之前未替換的+1
            }
        }
        return min(swap[sz - 1], unswap[sz - 1]);

    }
};
