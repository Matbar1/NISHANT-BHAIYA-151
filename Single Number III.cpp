class Solution {
public:
    vector<int> singleNumber(vector<int>& A) {
        int x = 0;
        for (int n : A) x ^= n;
        int lb = x & -(unsigned)x, a = 0;
        for (int n : A) {
            if (n & lb) a ^= n;
        }
        return {a, x ^ a};
    }
};