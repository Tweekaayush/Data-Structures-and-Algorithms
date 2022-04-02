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
queue<int> qu;

void neigh(vi adj[], bool frozen[]){
    int n = qu.size();
    while(n--){
        int temp = qu.front();
        qu.pop();
        if(frozen[temp]) continue;
        frozen[temp] = true;
        for(auto i: adj[temp]){
            qu.push(i);
        }
    }
}

void solve(){ 
    int V,e,q, c;
    cin>>V>>e>>q;
    c = V-1;
    bool frozen[V+1];
    vi adj[V+1];
    memset(frozen, false, sizeof(frozen));
    loop(i, 0, e){
        int u, v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    queue<int>qm;
    while(q--){
        int t, x;
        cin>>t>>x;
        switch(t){
            case 1: frozen[x] = true;
                    qm.push(x);
                    break;
            case 2: while(!qm.empty()){
                    int temp = qm.front();
                    qm.pop();
                        for(auto i: adj[temp]){
                            qu.push(i);
                        }
                    }
                    if(qu.empty() || c == 0) continue;
                    while(x-- and c>0){
                        neigh(adj, frozen);
                        c--;
                    }
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