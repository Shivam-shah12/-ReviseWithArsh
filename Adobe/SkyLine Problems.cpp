class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
       
        int temp;
        for(int i=0;i<buildings.size();++i){
            temp = buildings[i][0];
            buildings[i][0] = buildings[i][2];
            buildings[i][2] = temp;
        }
        vector<vector<int>> ans;
        priority_queue<vector<int>> pq;
        vector<int> cur;
        int i = 0;
        int height = 0;
        int right = 0;
        while(i<buildings.size()){
            
            while(!pq.empty()){
                cur = pq.top();
                if(cur[1]<=buildings[i][2]){
                    pq.pop();
                   
                    if(height==cur[0]){
                        right = cur[1];
                        while(!pq.empty() && pq.top()[1]<=right)pq.pop();
                        height = (!pq.empty())?pq.top()[0]:0;
                        if(cur[1]!=buildings[i][2]){
                            ans.push_back({right,height});
                        }else{
                            // find the max of the elements with same left end
                            temp = buildings[i][2];
                            while(i<buildings.size() && temp==buildings[i][2]){
                                pq.push(buildings[i]);
                                ++i;
                            }
                            if(pq.top()[0]>height && cur[0]!=pq.top()[0]){
                                height = pq.top()[0];
                                ans.push_back({temp,height});
                            }else if(cur[0]!=height && cur[0]!=pq.top()[0]){
                                cout<<cur[0]<<" "<<pq.top()[0]<<endl;
                                ans.push_back({right,height});
                            }else{
                                height = pq.top()[0];
                            }
                            if(i>=buildings.size())break;
                        }
                    }
                }else{
                    break;
                }
            }
            if(i>=buildings.size())break;
            // push all the elements at the left point at buildings[i][2]
            temp = buildings[i][2];
            while(i<buildings.size() && buildings[i][2]==temp){
                pq.push(buildings[i]);
                ++i;
            }
            if(pq.top()[0]>height){
                height = pq.top()[0];
                ans.push_back({temp,height});
            }
        }
        // clear the priority queue
        while(!pq.empty()){
            cur = pq.top();
            pq.pop();
            if(height==cur[0]){
                right = cur[1];
                while(!pq.empty() && pq.top()[1]<=right)pq.pop();
                height = (!pq.empty())?pq.top()[0]:0;
                ans.push_back({right,height});    
            }
        }
        return ans;
    }
};
