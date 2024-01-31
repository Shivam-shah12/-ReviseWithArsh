class Solution {
public:
    int minNonZeroProduct(int p) {
        long long md = 1000000007;
        long long x = (((long long)1 << p) - 2) % md, y = (((long long)1 << p) - 1) % md;
        long long res = 1;
        while (--p) {
            res *= res, res %= md;
            res *= x, res %= md;
        }
        res *= y, res %= md;
        return res;
    }
};
