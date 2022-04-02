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



struct Edge{
    int src;
    int dst;
    int wt;
};
bool cmp(Edge a, Edge b){
    return a.wt < b.wt;
}

int find(vi &parent, int x){
    return ((parent[x] == x) ? x: find(parent, parent[x]));
}

void Union(vi &parent, vi &rank, int a, int b){
    int ax = find(parent, a);
    int bx = find(parent, b);
    if(rank[ax] == rank[bx])
        rank[ax]++;
    if(rank[ax] > rank[bx])
        parent[bx] = ax;
    else    
        parent[ax] = bx;
}

int kruskals(vector<Edge> &arr, int V, int E){
    sort(arr.begin(), arr.end(), cmp);
    vi rank(V+1, 1);
    vi parent(V+1, 0);
    vector<Edge>res;
    loop(i, 0, V){
        parent[i] = i;
    }
    int i = 0, j = 0;
    while(i < V-1){
        Edge ce = arr[j];
        int ax = find(parent, ce.src);
        int bx = find(parent, ce.dst);
        if(ax != bx){
            res.pb(ce);
            Union(parent, rank, ax, bx);
            i++;
        }
        j++;
    }
    int ans = 0;
    for(auto i: res){
        ans += i.wt;
    }
    return ans;
}

void solve(){
    int V,E;
    cin>>V>>E;
    vector<Edge>arr(E);
    loop(i, 0, E){
        cin>>arr[i].src>>arr[i].dst>>arr[i].wt;
    }
    cout<<kruskals(arr, V, E);
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