// Alien Dictionary Problem.

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> g[26];
        for(int i=0;i<N-1;i++){
            int min_len=min(dict[i].length(),dict[i+1].length());
            for(int j=0;j<min_len;j++){
                if(dict[i][j]!=dict[i+1][j]){
                    g[dict[i][j]-'a'].push_back(dict[i+1][j]-'a');
                    break;
                }
            }
        }
        stack<int> st;
        vector<bool> vis(26,false);
        for(int i=0;i<26;i++){
            if(g[i].size()>0 && vis[i]==false){
                dfs(g,vis,i,st);
            }
        }
        string s="";
        while(!st.empty()){
            s+=(st.top()+97);
            st.pop();
        }
        return s;
    }
    void dfs(vector<int> g[],vector<bool> &vis,int start,stack<int> &st){
        vis[start]=true;
        for(auto x:g[start]){
            if(vis[x]==false){
                dfs(g,vis,x,st);
            }
        }
        st.push(start);
    }
};
