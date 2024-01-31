class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& special) {
        int n = 0;
        for( int i = 0; i<special.size(); i++ ) {
            if( special[i][4] < abs(special[i][0] - special[i][2]) + abs(special[i][1]-special[i][3]) )
                special[n++] = special[i];
        }

        map<pair<int, int>, vector<pair<int, pair<int, int> >> > mp;

        int cost = abs(start[0]-target[0]) + abs(target[1]-start[1]);
        mp[{start[0], start[1]}].push_back( {cost, {target[0], target[1]} } );
        for( int i = 0; i<n; i++ ) {
            cost = abs(start[0]-special[i][0]) + abs(start[1]-special[i][1]);
            mp[{ start[0], start[1] }].push_back( { cost, { special[i][0], special[i][1]} } );
           
            mp[{special[i][0], special[i][1]}].push_back( { special[i][4], {special[i][2], special[i][3]} } );
        }

        for( int i = 0; i<n; i++ ) {
            cost = abs(special[i][2]-target[0]) + abs(special[i][3]-target[1] );
            mp[{special[i][2], special[i][3]}].push_back( { cost, {target[0], target[1]} } );

            for( int j = 0; j<n; j++ ) {
                if( i == j )
                    continue;
                cost = abs(special[i][2]-special[j][0]) + abs(special[i][3]-special[j][1] );
                mp[{special[i][2], special[i][3]}].push_back( { cost, { special[j][0], special[j][1] } });
            }
        }

    
        priority_queue< pair<int, pair<int, int>> > pq;
        map< pair<int, int>, int> mp1;

        pq.push( {0, {start[0], start[1]} } );
        mp1[{start[0], start[1]}] = 0;
        set<pair<int, int> > st;
        
        while( !pq.empty() ) {
            auto cur = pq.top().second;
            auto val = -pq.top().first;
            if( cur.first == target[0] and cur.second == target[1] )
                return val;
            pq.pop();
            if( st.find( cur ) != st.end() )
                continue;
            st.insert( cur );
            for( auto it : mp[cur] ) {
                if( !mp1[it.second] || mp1[it.second] > val + it.first ) {
                    mp1[it.second] = val + it.first;
                    pq.push( { -mp1[it.second], it.second } );
                }
            }
        }
        return -1;
    }
};
