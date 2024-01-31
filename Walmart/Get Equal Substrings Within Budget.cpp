class Solution {
public:
    int minLen(vector<int>& arr,int maxCost)
    {
        int currSum=0;
        int max_len=0;
        int i=0;int j=0;
        int n=arr.size();
        while(j<n)
        {
           currSum+=arr[j];
           while(currSum>maxCost)
           {
               currSum-=arr[i];
               i++;
           }
           max_len=max(max_len,j-i+1);
           j++;
        }
        return max_len;
       
    }
    int equalSubstring(string s, string t, int maxCost) {

        int n=s.length();
        vector<int>arr(n);
        for(int i=0;i<n;i++)
        {
            int diff=abs(s[i]-t[i]);
            arr[i]=diff;
        }
        for(auto val:arr)
        cout<<val<<" ";
        cout<<endl;
        return minLen(arr,maxCost);
        
    }
};
