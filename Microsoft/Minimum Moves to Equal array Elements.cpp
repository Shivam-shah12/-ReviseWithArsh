class Solution {
public:
   vector<int>deltaX={-1,-1,0,1,1,1,0,-1};
   vector<int>deltaY={0,1,1,1,0,-1,-1,-1};

    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>>ans=img;
        for(int i=0;i<img.size();i++)
        {
            for(int j=0;j<img[i].size();j++)
            {
                 
                 int sum=img[i][j];
                 int count=1;
                 for(int k=0;k<deltaX.size();k++)
                 {
                    int  x=i+deltaX[k];
                    int  y=j+deltaY[k];
                     if(x>=0 && x<img.size() && y>=0 && y<img[0].size())
                     {
                         sum+=img[x][y];
                         count++;
                     }
                     
                 }
                 // cout<<sum<<" "<<count<<endl;
                 ans[i][j]= floor(sum/count);
            }
        }

     return ans;
        
    }
};
