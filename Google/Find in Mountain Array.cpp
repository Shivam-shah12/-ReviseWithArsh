/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        const int n = mountainArr.length();
        int top = n - 1;
        int lo = 1;
        int hi = n -  1;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (mountainArr.get(mid) > mountainArr.get(mid + 1)) {
                top = min(top, mid);
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        lo = 0;
        hi = top;
        int ans = n;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            const int val = mountainArr.get(mid);
            if (val == target) {
                ans = min(ans, mid);
                hi = mid - 1;
            } else if (val < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        lo = top + 1;
        hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            const int val = mountainArr.get(mid);
            if (val == target) {
                ans = min(ans, mid);
                hi = mid - 1;
            } else if (val < target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return ans == n ? -1 : ans;
    }
};
