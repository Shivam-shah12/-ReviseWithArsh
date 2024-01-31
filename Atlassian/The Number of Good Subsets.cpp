class Solution {
public:
#define ll long long
long long M=1e9+7;
long long mod(long long x){
            return ((x%M + M)%M);
        }
        long long add(long long a, long long b){
            return mod(mod(a)+mod(b));
        }
        long long mul(long long a, long long b){
            return mod(mod(a)*mod(b));
        }
    
        long long modPow(long long a, long long b){
            if(b==0)
                return 1LL;
            if(b==1)
                return a%M;
            ll res=1;
            while(b){
                if(b%2==1)
                    res=mul(res,a);
                a=mul(a,a);
                b=b/2;
            }
            return res;
        }
map<int,int> a;
vector<int> c={2,3,5,7,11,13,17,19,23,29};
long long dp[32][1025];
long long helper(vector<int> &m, int ind, long long mask) {
    if (ind == 31) return 1;
    if (dp[ind][mask] != -1) return dp[ind][mask];

    long long np = helper(m, ind + 1, mask) % M;

    int newMask = mask;
    for (auto prime : c) {
        if (ind % prime == 0) {
            if (!(mask & (1 << a[prime]))) {
                return dp[ind][mask] = np;
            } else {
                newMask ^= (1 << a[prime]);
            }
        }
    }
    long long p = mul(m[ind], helper(m, ind + 1, newMask));
    return dp[ind][mask] = (np+p) % M;
}
    int numberOfGoodSubsets(vector<int>& nums) {
        vector<int> m(31,0);
        memset(dp,-1,sizeof(dp));
        long long one=0;
        for(auto i:nums){
            if(i==1)one++;
            if(i%4==0 || i%9==0 || i%25==0)continue;
            m[i]++;
            

        }
        a[2]=0,a[3]=1,a[5]=2,a[7]=3,a[11]=4,a[13]=5,a[17]=6,a[19]=7,a[23]=8,a[29]=9;
        long long mask=0;
        mask=(1<<10)-1;
        long long res=helper(m,2,mask);
        res--;//remove the case of all elements empty
        long long f=modPow(2,one);
        long long ans=mul(res,f)%M;
        return ans;
    }
};
