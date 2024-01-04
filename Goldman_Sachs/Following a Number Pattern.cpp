class Solution{   
public:
    void reverse(int i,int j,string& arr)
    {
        while(i<=j)
        {
            swap(arr[j],arr[i]);
            i++;
            j--;
        }
    }
    
    string printMinNumberForPattern(string s){
        string str="";
        for(int i=1;i<=s.length()+1;i++)
        {
            str+=to_string(i);
        }
        // cout<<str<<endl;
        // 1 2 3 4 5 6
        // I I D D D
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='I')
            continue;
            else if(s[i]=='D')
            {
                int j=i+1;
                while(j<s.size())
                {
                    if(s[j]!='D')
                    break;
                    j++;
                }
                // cout<<"j = "<<j<<endl;
                reverse(i,j,str);
                i=j-1;
            }
        }
        return str;
    }
};