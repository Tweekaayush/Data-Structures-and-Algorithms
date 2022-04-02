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

bool dfs(vi adj[], int vis[], int src, int par){
    vis[src] = 1;
    bool cycle = false;
    for(auto i: adj[src]){
        if(vis[i] and i == par) continue;
        if(vis[i]) return true;
        cycle = dfs(adj, vis, i, src);
    }
    return cycle;
}

void solve(){
    int v, e, c= 0;
    cin>>v>>e;
    vector<int> adj[v+1];
    loop(i, 0, e){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int vis[v + 1]= {}, f =0;
    for(int i = 1; i<=v; i++){
        bool cycle = false;
        if(!vis[i]){
            c++;
            cycle = dfs(adj, vis, i, 0);
        }
        if(cycle){
            f = 1;
            break;
        }
    }
    if(f)cout<<"cycle Exists";
    else cout<<"cycle does not exist";
    cout<<nl;
}

int32_t main(){
    FIO;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}