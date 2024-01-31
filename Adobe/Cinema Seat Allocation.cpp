class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reser) {
        int ans = 0;
        unordered_map<int,vector<int>> mp;
        for(auto r: reser){
            mp[r[0]].push_back(r[1]-1);
        }
        int group=(n-mp.size())*2;
        for(auto i:mp){
            vector<bool>seats(10,1);
            for(auto x:i.second){
                seats[x]=0;
            }
            int left=0;
            int right=0;
            int mid=0;
            if(seats[1]==1 && seats[2]==1 && seats[3]==1 && seats[4]==1){
                left=1;
            }
            if(seats[5]==1 && seats[6]==1 && seats[7]==1 && seats[8]==1){
                right=1;
            }
            if(seats[3]==1 && seats[4]==1 && seats[5]==1 && seats[6]==1){
                mid=1;
            }
            group+=max(left+right,mid);
        }
        return group;
    }
};
