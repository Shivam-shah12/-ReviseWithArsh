class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin() , ages.end() ,greater<int> ());
        
        int ans = 0;
        int n = ages.size();
        for(int i = 0; i < n;) {
            int lo = i , hi = n - 1;
            int temp = 0;
            while(lo <= hi) {
                int mid = (lo + hi) >> 1;
                if(ages[mid] <= ages[i] and (2 * ages[mid] > ages[i] + 14)and !(ages[mid] > 100 and ages[i] < 100)) {
                    lo = mid + 1;
                    if(mid != i)
                        temp = mid;
                } else hi = mid - 1;
            }
            int tp = (temp - i  < 0 ? 0 : temp - i);
            while(i + 1 < n and ages[i] == ages[i + 1]) {
                ans += tp;
                i++;
            }
            ans += tp;
            i++;
        }
        return ans;
    }
};
