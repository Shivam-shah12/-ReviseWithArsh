class Solution {
public:
    int countCollisions(string directions) {
        int ans = 0;
        char a = directions[0];
        int x = 0;
        for(int i = 1;i < directions.size();i++){
            char b = directions[i];
            if(a == 'R' && b == 'L'){
                ans += 2 + x;
                x = 0;
                a = 'S';
            }
            else if(a == 'S' && b == 'L'){
                ans += 1 + x;
                a = 'S';
                x = 0;
            }
            else if(a == 'R' && b == 'S'){
                ans += 1 + x;
                x = 0;
                a = 'S';
            }
            else{
                if(a == 'R' && b == 'R')
                    x++;
                a = b;
            }
        }
        return ans;
    }
};
