class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, std::vector<int>& hBars, std::vector<int>& vBars) {
        std::sort(hBars.begin(), hBars.end());
        std::sort(vBars.begin(), vBars.end());

        int maxHcon = 0;
        int maxVcon = 0;
        int len_h = hBars.size();
        if (len_h != 0) {
            maxHcon = 1;
        }
        int len_v = vBars.size();
        if (len_v != 0) {
            maxVcon = 1;
        }
        int count = 1;

        for (int i = 0; i < len_h - 1; ++i) {
            int inc = hBars[i] + 1;
            if (hBars[i + 1] == inc) {
                count += 1;
                if (count > maxHcon) {
                    maxHcon = count;
                }
            } else {
                count = 1;
            }
        }

        count = 1;

        for (int i = 0; i < len_v - 1; ++i) {
            int inc = vBars[i] + 1;
            if (vBars[i + 1] == inc) {
                count += 1;
                if (count > maxVcon) {
                    maxVcon = count;
                }
            } else {
                count = 1;
            }
        }

        int ans = 1;

        if (maxVcon > 0) {
            maxVcon += 1;
        }

        if (maxHcon > 0) {
            maxHcon += 1;
        }

        ans = std::min(maxVcon, maxHcon);

        if (maxVcon > 0 && maxHcon > 0) {
            return ans * ans;
        } else if (maxVcon > 0 && maxHcon == 0) {
            if (len_h == 1) {
                return 4;
            } else {
                return 1;
            }
        } else if (maxVcon == 0 && maxHcon > 0) {
            if (len_v == 1) {
                return 4;
            } else {
                return 1;
            }
        } else {
            return 1;
        }
    }
};
