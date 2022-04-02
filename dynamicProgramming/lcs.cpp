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

int dp[10000][10000] = {};
int lcsTD(string s1, string s2, int n, int m){
    if(n == 0 || m == 0)
        return 0;
    if(dp[n][m] != -1)
        return dp[n][m];
    if(s1[n-1] == s2[m-1])
        return dp[n][m] = 1 + lcsTD(s1, s2, n- 1, m-1);
    return dp[n][m] = max(lcsTD(s1, s2, n-1, m), lcsTD(s1, s2, n, m-1));
}

int lcsBU(int n, int m, string s1, string s2)
    {
        // your code here
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i = 1;i <= n; i++)
            for(int j = 1; j <= m; j++)
                if(s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        return dp[n][m];
    }

void solve(){
    string s1, s2;
    cin>>s1>>s2;
    memset(dp, -1, sizeof dp);
    cout<<lcsTD(s1, s2, s1.length(), s2.length())<<nl;
    cout<<lcsBU(s1.length(), s2.length(), m, s1, s2)<<nl;
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