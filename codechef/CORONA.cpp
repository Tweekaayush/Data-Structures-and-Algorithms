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

void dijkstra(vector<vector<pii>>adj, int V){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vi dist(2*V+1, inf);
    loop(i, V+1, 2*V+1){
        dist[i] = 0;
        pq.push(mp(0, i));
    }
    while(!pq.empty()){
        int temp = pq.top().second;
        pq.pop();
        for(auto i: adj[temp]){
            int v = i.first;
            int wt = i.second;
            if(dist[v] > dist[temp] + wt)
            {
                dist[v] = dist[temp] + wt;
                pq.push(mp(dist[v], v));
            }
        }
    }
    loop(i, 1, V+1){
        cout<<dist[i]<<" ";
    }
}

void solve(){
    int n, m, k,v;
    cin>>n>>m>>k;
    v  = 2*n+1;
    vector<vector<pii>> adj(2 * n+1);
    int i =1;
    while(k--){
        int nde, cst;
        cin>>nde>>cst;
        adj[nde].pb(mp(n+i, cst));
        adj[nde + n].pb(mp(i, cst));
        i++;
    }
    loop(i, 0, m){
        int u, v, wt;
        cin>>u>>v>>wt;
        adj[u].pb(mp(v, wt));
        adj[v].pb(mp(u, wt));
    }
    dijkstra(adj, n);
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
        cout<<nl;
    }
    return 0;
}