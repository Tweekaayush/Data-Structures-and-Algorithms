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

string lcsBU(int n, int m, string s1, string s2)
    {
        // your code here
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i = 1;i <= n; i++)
            for(int j = 1; j <= m; j++)
                if(s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        string ans;
    int i = n, j = m;
    while(i > 0 && j > 0)
    {
        if(s1[i - 1] == s2[j - 1])
        {
            ans.push_back(s1[i-1]);
            i--;
            j--;
        }
        else if(dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

void solve(){
    int i, j, n, m;
    string s1, s2;
    cin>>s1>>s2;
    n = s1.length();
    m = s2.length();
    if(n > m){
        cout<<"IMPOSSIBLE"<<nl;
        return;
    }
    i = j = 0;
    while(i<n and j <m){
        if(s1[i] == s2[j]){
            i++;
            j++;
        }
        else j++;
    }
    if(i == n){
        cout<<m-n<<nl;
    }
    else cout<<"IMPOSSIBLE"<<nl;
}

int32_t main(){
    FIO;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t, i = 1;
    cin>>t;
    while(t--){
        cout<<"Case #"<<i<<": ";
        i++;
        solve();
    }
    return 0;
}