/*
* step 1: get the statistical data of each number
* step 2: for every number: check if
    * step 2-1: if this number can be used as the tail of already-constructed answer, then just insert it into!
    * step 2-2: if this number can be used as the start of new one, then add freq_seq[num], freq_seq[num + 1], freq_seq[num + 2] by one
* use freq_nums to keep tracking the remaining quantity of each number
* use freq_seq to keep tracking the end of the consecutive subsequence which has been constructed before
*/

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int, int> freq_nums;
        map<int, int> freq_seq;
        for(int x : nums){
            freq_nums[x]++;
        }
        

        freq_seq[nums[0] - 1] = 1; // dummy
        for(int x : nums){
            if(!freq_nums[x]){
                continue;
            }
            // step 2-1
            else if(freq_seq[x]){
                freq_seq[x]--; // delete the current tail
                freq_seq[x + 1]++; // update the tail , i.e. next pospsible starting number to concatenate
                
                freq_nums[x]--; // use such element
            }
            // step 2-2
            else if(freq_nums[x + 1] && freq_nums[x + 2]){
                freq_seq[x + 3]++; // update the tail, i.e. next pospsible starting number to concatenate
                
                freq_nums[x]--; // use such element
                freq_nums[x + 1]--; // use such element
                freq_nums[x + 2]--; // use such element
            }
            // does nothing
            else{
                return false;   
            }
        }
        return true;
    }
};