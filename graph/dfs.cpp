#include<bits/stdc++.h>
using namespace std;

vector<int> res;

void dfs(int vis[], vector<int>adj[], int src){
    vis[src] = 1;
    res.push_back(src);
    for(auto i: adj[src])
        {
            if(vis[i] != 1)
                dfs(vis, adj, i);
        }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int V, E;
    cin>>V>>E;
    vector<int> adj[V];
    for(int i = 0 ; i < E; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    int vis[V] = {0};
    dfs(vis, adj, 0);
    for(auto i : res){
        cout<<i<<" ";
    }
    return 0;
}