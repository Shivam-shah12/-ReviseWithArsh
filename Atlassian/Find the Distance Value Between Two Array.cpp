class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
        int n=arr2.size();
        int ans=0;
        
        for(int i=0;i<arr1.size();i++){
            int flag=0;
            int l=0,r=n-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(abs(arr1[i]-arr2[mid])<=d){
                    flag=1;
                    break;
                }else if(arr1[i]<arr2[mid])r=mid-1;
                else l=mid+1;
            }
            if(flag==0)ans++;
        }
        return ans;
    }
};
