/*Faster version, use bitset
* Step 1: Construct a bitset representing the usage of characters in each possible starting string.
* Step 2: For each possible starting string, check if starting string is unique, if yes, starting from it, else no
* Step 3: Keep concatenating by using the bitset to count the characters usage, use binary OR for concatenated strings.
* Repeated 2 and 3 above for final answer
*/
class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        
        // Step 1
        vector<bitset<26> > alpha_cnt;
        vector<bitset<26> > all_comb;
        
        for(string str : arr){
            bitset<26>b;
            for(char c : str){
                b.set(c - 'a');
            }
            alpha_cnt.push_back(b);
        }
        
        // Step 2: Trying all possible concatenations
        int res = 0;
        for(int i = 0; i < n; i++){
            if(alpha_cnt[i].count() != arr[i].size()){
                continue;
            }
            else{
                // Step 3: 
                res = max(res, (int)alpha_cnt[i].count());
                all_comb.push_back(alpha_cnt[i]);
                for(int j = all_comb.size() - 1; j >= 0; j--){

                    // such combination contains duplicate character
                    if((alpha_cnt[i] & all_comb[j]).any()){
                        continue;
                    }
                    all_comb.push_back(alpha_cnt[i] | all_comb[j]);
                    res = max(res, (int)(alpha_cnt[i] | all_comb[j]).count());
                }
            }
        }
        
        return res;
    }
};