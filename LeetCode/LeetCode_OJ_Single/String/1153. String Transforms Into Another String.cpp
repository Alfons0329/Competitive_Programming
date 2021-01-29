class Solution
{
public:
    bool canConvert(string str1, string str2)
    {
        // some primitive
        if (str1 == str2){
            return true;
        }
        // Step 1
        unordered_map<char, char> m;
        int n = str1.size();

        // Step 2
        for (int i = 0; i < n; i++){
            // if character in 1 != in 2, then constrcut the mapping
            if (str1[i] != str2[i]){
                // the mapping has 1 to multi mapping, so fail (one char does not change multiple times)
                if (m.find(str1[i]) != m.end() && m[str1[i]] != str2[i]){
                    return false;
                }
                m[str1[i]] = str2[i];
            }
        }

        // need one charadcter for temporary transition 
        return set(str2.begin(), str2.end()).size() < 26;
    }
};