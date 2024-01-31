class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        int at=0,bt=0;
        int n=a.size();
        vector<pair<int,int>>v1;
        for(int i=0;i<n;i++){
            v1.push_back({a[i]+b[i],i});
        }
        sort(v1.begin(),v1.end(),greater<pair<int,int>>());
        for(int i=0;i<v1.size();i++){
            if(i%2==0){
                at+=a[v1[i].second];
            }else bt+=b[v1[i].second];
        }
        
        if(at>bt)return 1;
        else if(at<bt)return -1;
        else return 0;
    }
};
