//minimum spanning tree
#include<bits/stdc++.h>
using namespace std;

#define ff first 
#define ss second
#define int long long int 
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pq_max priority_queue<int>
#define pq_min priority_queue<int,vi,greater<int> >
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

void dijkstra(vector<pii>arr[], int V, int s){
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    vi dist(V, inf);
    dist[s] = 0;
    vi vis(V, 0);
    pq.push(mp(0 , s));
    while(!pq.empty()){
        int temp = pq.top().second;
        pq.pop();
        for(auto i: arr[temp]){
            int v = i.first;
            int weight = i.second;
            if (dist[v] > dist[temp] + weight)
            {
                dist[v] = dist[temp] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    loop(i, 0,V){
        cout<<dist[i]<<" ";
    }
    cout<<nl;
}

void solve(){
    int V,E,s;
    cin>>V>>E;
    vector<pii>arr[V];
    loop(i, 0, E){
        int u, v, w;
        cin>>u>>v>>w;
        arr[u].pb(mp(v, w));
        arr[v].pb(mp(u, w));
    }
    cin>>s;
    dijkstra(arr, V, s);
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