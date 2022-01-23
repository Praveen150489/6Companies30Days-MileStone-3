// Given a Graph of V vertices and E edges and another edge(c - d), the task is to find if the given edge is a Bridge. i.e., removing the edge disconnects the graph.

class Solution
{
	public:
	void solve(int start,vector<int> adj[],vector<bool>& vis,int c,int d){
	    vis[start]=true;
	    for(auto x:adj[start]){
	        if(start==c && x==d){
	            continue;
	        }
	        else if(start==d && x==c){
	            continue;
	        }
	        else if(vis[x]==false){
	            solve(x,adj,vis,c,d);
	        }
	    }
	}
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d)
    {
        // Code here
        vector<bool> vis(V,false);
        solve(c,adj,vis,c,d);
        if(vis[d]==false){
            return 1;
        }
        return 0;
    }
};
