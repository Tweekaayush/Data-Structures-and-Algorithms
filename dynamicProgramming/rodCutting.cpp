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

int rodCutting(int n, int a, int b, int c){
    int dp[n+1];
    dp[0]=0;
    for(int i = 1; i <=n; i++){
        dp[i]=-1;
        if(i-a >= 0) dp[i] = max(dp[i], dp[i-a]);
        if(i-b >= 0) dp[i] = max(dp[i], dp[i-b]);
        if(i-c >= 0) dp[i] = max(dp[i], dp[i-c]);
        if(dp[i]!=-1)
            dp[i]++;
    }
    if(dp[n] != -1)
    return dp[n];
    return 0;
}

void solve(){
    int n, a, b, c;
    cin>>n>>a>>b>>c;
    cout<<rodCutting(n, a, b, c)<<nl;
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