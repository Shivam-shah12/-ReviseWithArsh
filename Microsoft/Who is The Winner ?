class Solution {
public:
    int solve(int n , int k){
        if(n==1)
        return 0;
        cout<<n-1<<endl;
        return (solve(n-1,k)+k)%n;
    }
    int findTheWinner(int n, int k) {
        return solve(n, k)+1;
    }
};
