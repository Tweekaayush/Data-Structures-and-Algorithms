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

void bfs(vi adj[], int v, int s){
    int vis[v+1] = {0}, temp;
    queue<int>q;
    q.push(s);
    vis[s] = 1;
    vi parent(v+1, 0);
    vi res;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        res.pb(temp);
        for(auto i: adj[temp]){
            if(vis[i] != 1){
                q.push(i);
                vis[i] = 1;
            }
        }
    }
    for(auto i: res){
        cout<<i<<" ";
    }
}

void solve(){
    int V,e,s;
    cin>>V>>e;
    vi adj[V];
    loop(i, 0, e){
        int u, v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<vector<int>>res;
	    for(int i=0;i<V;i++){
	        vector<int> ans;
	        for(auto it: adj[i])
	            ans.push_back(it);
	       res.push_back(ans);
	    }
        
        for(int i = 0; i < res.size(); i++){
	        cout<<i;
	        for(auto it: res[i]){
	            cout<<"-> "<< it;
	        }
	        cout<<endl;
	    }
    cin>>s;
    //bfs(adj, V, s);
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