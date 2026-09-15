class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            int bitsA = __builtin_popcount(a); //kuno shonkhar binary representation e kotogula 1 bit ache ta count kore
            int bitsB = __builtin_popcount(b);
            if (bitsA == bitsB)
                return a < b;
            return bitsA < bitsB;
        });
        return arr;
    }
};