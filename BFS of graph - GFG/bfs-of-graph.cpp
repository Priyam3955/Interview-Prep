//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> v;
        queue<int> q;
        q.push(0);
        vector<int> vis(V,0);
        vis[0] = 1;
        
        while(!q.empty()){
            int td = q.front();
            q.pop();
            v.push_back(td);
            for(auto x : adj[td]){   // Adjacency List given . process All elems at particular node at once
                if(!vis[x]){
                    vis[x] = 1;
                    q.push(x);
                }
            }
        }
        return v;
    }
    
    /* int v,e;            // Making of Graph
       cin>>v>>e;           // 1 based indexing works
       vector<int> g[v+1];
       for(int i=0;i<e;i++){
           int x,y;
           cin>>x>>y;
           g[x].push_back(y);
           g[y].push_back(x);
       }
       
       for(int i=1; i<=v;i++){
           cout<<i<<"--> ";
           for(int j=0;j<g[i].size();j++){
               cout<<g[i][j];
           }
           cout<<endl;
       }
    */
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends