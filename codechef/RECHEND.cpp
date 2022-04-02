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

bool isSafe(vector<vector<int>> &v, int n, int i, int j){
    return i >=0 && i < n && j >=0 && j < n && v[i][j] != 1;
}

void func(vector<vector<int>> &v, int n, int i, int j, int &f){
    if(i == n-1 && j == n-1){
        f = 0;
        return;
    }
    if(!isSafe(v, n, i , j))
        return;
    if((i + 1) < n and v[i + 1][j] == 0)
        func(v, n, i + 1, j, f);
    if((j + 1) < n and v[i][j + 1] == 0)
        func(v, n, i, j + 1, f);
    return;
}

void solve(){
    int n, f = 1;
    cin>>n;
    vector<vector<int>> v(n, vector<int>(n, 0));
    loop(i, 0, n){
        int u, ve;
        cin>>u>>ve;
        v[u-1][ve-1] = 1;
    }
    func(v, n, 0, 0, f);
    if(f == 1)
        cout<<"No"<<nl;
    else cout<<"Yes"<<nl;
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