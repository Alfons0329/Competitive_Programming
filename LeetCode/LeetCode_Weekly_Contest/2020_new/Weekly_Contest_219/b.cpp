class Solution {
public:
    int minPartitions(string n) {
        sort(n.begin(), n.end());
        return n.back() - '0';
    }
