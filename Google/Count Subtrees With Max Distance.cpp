class Solution {
public:
void make(int a,int parent[],int len[])
{
    parent[a]=a;
    len[a]=1;
}

int find_(int a,int parent[])
{
    if(a==parent[a])
        return a;
    //path compression
    int ans=find_(parent[a],parent);
    parent[a]=ans;
    return ans;
}

void Union(int a,int b,int parent[],int len[])
{
    int x=find_(a,parent);
    int y=find_(b,parent);
    if(x==y)
        return;
    //union by size
    if(len[x]<len[y])
        swap(x,y);
    parent[y]=x;
    len[x]+=len[y];
}


bool connected(int n,vector<int>& temp,vector<vector<int>> matrix)
{
    int parent[n],len[n];
    for(int i=0;i<n;i++)
        make(i,parent,len);
    for(int i=0;i<temp.size();i++)
    {
        for(int j=i+1;j<temp.size();j++)
        {
            int a=temp[i],b=temp[j];
            if(matrix[a][b])
                Union(a,b,parent,len);
        }
    }
    map<int,int> m;
    for(int x:temp)
    {
        int par=find_(x,parent);
        m[par]++;
    }
    return m.size()==1;
}
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> matrix(n,vector<int>(n,0));
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++)
            dist[i][i]=0;
        for(auto v:edges)
        {
            int x=v[0]-1,y=v[1]-1;
            dist[x][y]=1;
            dist[y][x]=1;
            matrix[x][y]=1;
            matrix[y][x]=1;
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(dist[i][k]==1e9 || dist[k][j]==1e9)
                        continue;
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        vector<int> res(n-1,0);
        int sz=1<<n;
        for(int i=1;i<sz;i++)
        {
            vector<int> temp;
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                    temp.push_back(j);
            }
            if(temp.size()==1)
                continue;
            if(!connected(n,temp,matrix))continue;
            int maxi=0;
            for(int a=0;a<temp.size();a++)
            {
                for(int b=a+1;b<temp.size();b++)
                {
                    maxi=max(maxi,dist[temp[a]][temp[b]]);
                }
            }
            if(maxi)
                res[maxi-1]++;
        }
        return res;
    }
};
