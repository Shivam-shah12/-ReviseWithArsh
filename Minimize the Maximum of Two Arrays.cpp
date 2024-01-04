class Solution {
public:
long long gcd(long long a, long long b){
        if(b == 0)  return a;
        return gcd(b, a % b);
    }
    int minimizeSet(int d1, int d2, int u1, int u2) {
        long long answer = LLONG_MAX;
        long long  low = 1, high = LLONG_MAX;

        long long lcm = (d1 / gcd(d1, d2)) * d2;

        while(low <= high){
            long long mid = low + (high - low)/2; 
            long long totalOne = mid - mid/d1;
            long long totalTwo = mid - mid/d2;

            long long both = mid - mid / lcm;

            if(totalOne >= u1 && totalTwo >= u2 && both >= u1 + u2){
                high = mid - 1;
                answer = mid;
            }
            else{
                low = mid + 1;
            }
        }

        return (int)(answer);
    }
