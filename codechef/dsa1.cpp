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

void solve(){
    int n, m;
    cin>>n>>m;
    int mat[n][m];
    vi r;
    vi c;
    loop(i, 0, n){
        loop(j, 0, m){
            cin>>mat[i][j];
            if(mat[i][j] == 1){
                r.push_back(i);
                c.push_back(j);
            }
        }
    }
    for(auto i: r){
        for(int j = 0; j < m; j++){
            mat[i][j] = 1;
    }
    }
    for(int j = 0; j < n; j++){
        for(auto i: c)
            mat[j][i] = 1;
    }

    loop(i, 0, n){
        loop(j, 0, m){
            cout<<mat[i][j]<<" ";
        }
        cout<<nl;
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