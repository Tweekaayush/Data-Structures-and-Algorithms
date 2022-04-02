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

void dfs(int src, int par, int height[], int depth[], vi adj[]){
    for(auto i: adj[src]){
        if(i == par) continue;
        depth[i] = depth[src] + 1;
        dfs(i, src, height, depth, adj);
        height[src] = max(height[src], height[i] + 1);
    }
}

void solve(){
    int v;
    cin>>v;
    vi adj[v+1];
    int height[v+1] = {};
    int depth[v+1] = {};
    for(int i = 0; i < v-1;i++){
        int u, v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, 0, height, depth, adj);
    cout<<"  Depth  Height"<<nl;
    loop(i, 1, v+1){
        cout<<i<<":   "<<depth[i]<<"\t"<<height[i]<<nl;
    }
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