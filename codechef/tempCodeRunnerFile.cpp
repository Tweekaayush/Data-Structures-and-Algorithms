#include<bits/stdc++.h>
using namespace std;

#define ff first 
#define ss second
#define int long long int 
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pqb priority_queue<int>
#define mod 1000000007
#define ps(x, y) fixed<<setprecision(y)<<x
#define loop(i, lb, ub) for(int i = lb; i < ub; i++)
#define looprev(i, lb, ub) for(int i = lb; i >= ub; i--)
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inf 1e18
#define nl "\n"
#define vs vector<string>
#define log(args...) {string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cout << *it << " = " << a << std::endl;
    err(++it, args...);
}


void dfs(int vis[], vi adj[], bool frozen[], int x, int V, int src, int &c){
    vis[src] = 1;
    if(x==0) return;
    for(auto i: adj[src])
        {
            if(vis[i] != 1 and x > 0){
                if(frozen[i])
                    dfs(vis, adj, frozen, x, V, i);
                else{
                    c++;
                    frozen[i] = true;
                    dfs(vis, adj, frozen, x-1, V, i);
                }
            }
        }
}
void neigh(vi adj[], bool frozen[], int x, int V, int &c){
    int vis[V+1] = {};
    for(int i = 1; i <= V; i++){
        if(!vis[i] and frozen[i]){
            dfs(vis, adj, frozen, x, V, i, c);
        }
    }
}
void solve(){ 
    int V,e,q,c=0;
    cin>>V>>e>>q;
    bool frozen[V+1];
    vi adj[V+1];
    memset(frozen, false, sizeof(frozen));
    loop(i, 0, e){
        int u, v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    while(q--){
        int t, x;
        cin>>t>>x;
        switch(t){
            case 1: frozen[x] = true;
                    c++;
                break;
            case 2:     if(c != V)           
                            neigh(adj, frozen, x, V, c);
                        break;
            case 3: if(frozen[x] == true)
                        cout<<"YES"<<nl;
                    else cout<<"No"<<nl;
            break;
        }
    }
}

int32_t main(){
    FIO;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    solve();
    return 0;
}