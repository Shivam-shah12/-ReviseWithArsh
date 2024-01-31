class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<string> st;
        int i=0;
        int n = preorder.size();
        string s="";
        while(i<n){
            s = "";
            if(isdigit(preorder[i])){
                while(i<n && isdigit(preorder[i])){
                    s += preorder[i];
                    i++;
                }
                st.push(s);
                i++;
            }
            else{
                s = preorder[i];
                i += 2;
                while(!st.empty() && st.top() == s){
                    st.pop();
                    if(!st.empty()){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                st.push(s);
            }
        }
        if(st.size() == 1 && st.top() == "#") return true;
        return false;
    }
};
