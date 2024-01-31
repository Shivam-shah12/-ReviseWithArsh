class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> freq_of_loss;
        // vector<int> player_ids;
        for(int i=0;i<matches.size();++i)
        {
            int winner=matches[i][0];
            int loser=matches[i][1];
        
            freq_of_loss[winner]+=0;
            freq_of_loss[loser]+=1;
        }
        vector<vector<int>> answer(2);
        for(auto& it: freq_of_loss)
        {
           if(it.second==0)
           {
               answer[0].push_back(it.first);
           }
           if(it.second==1)
           {
               answer[1].push_back(it.first);
           }
        }
        sort(answer[0].begin(),answer[0].end());
        sort(answer[1].begin(),answer[1].end());
        return answer;
    }
};
