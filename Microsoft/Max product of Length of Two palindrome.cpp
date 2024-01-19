class Solution {
public:
    int maxProduct(std::string s) {

        int n = s.size();
        std::vector<std::pair<int, int>> arr;

        for (int mask = 1; mask < (1 << n); ++mask) {
            std::string subseq;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    subseq += s[i];
                }
            }

            if (subseq == std::string(subseq.rbegin(), subseq.rend())) {
                arr.emplace_back(mask, subseq.size());
            }
        }

        int result = 1;
        // Iterate over all pairs of disjoint subsequences
        for (const auto& [mask1, len1] : arr) {
            for (const auto& [mask2, len2] : arr) {

                if ((mask1 & mask2) == 0) {
                    result = std::max(result, len1 * len2);
                }
            }
        }

        return result;
    }
};
