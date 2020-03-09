/*
* This failed with edge case: 
"abcdefghijklmnopqrstuvwxyz"
"bcdefghijkamnopqrstuvwxyzl"
* Step 1: use unordered_map<char, char>, find the mapping relation
* Step 2: aabcc vs ccdee, iterate through the 2 strings 
* Step 3: if str1[i] != str2[i], construct the mapping, so the overall mapping will be
a --> c
b --> d
c --> e

* Step 4: iterate though str1 again, and then change change the character according to mapping
* Step 5: return changed(str1) == str2
*/

class Solution
{
public:
    bool canConvert(string str1, string str2)
    {
        // some primitive
        if (str1 == str2)
        {
            return true;
        }
        // Step 1
        unordered_map<char, char> m;
        int n = str1.size();

        // Step 2
        for (int i = 0; i < n; i++)
        {
            // if character in 1 != in 2, then constrcut the mapping
            if (str1[i] != str2[i])
            {
                // the mapping has 1 to multi mapping, so fail (one char does not change multiple times)
                if (m.find(str1[i]) != m.end() && m[str1[i]] != str2[i])
                {
                    return false;
                }
                m[str1[i]] = str2[i];
            }
        }

        // need one charadcter for temporary transferring
        return set(str2.begin(), str2.end()).size() < 26;
    }
};