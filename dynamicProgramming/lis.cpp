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

int ceilIdx(int dp[], int l, int r, int x){
    while(r>l){
        int m = l + (r-l)/2;
        if(dp[m]>=x)
            r = m;
        else l = m + 1;
    }
    return r;
}

int lisBU(int arr[], int n){
    int dp[n] = {}, len = 1;
    dp[0] = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > dp[len-1])
            {
                dp[len] = arr[i];
                len++;
            }
        else{
            int ceilP = ceilIdx(dp, 0, len-1, arr[i]);
            dp[ceilP] = arr[i];
        }
    }
    loop(i, 0, len){
        cout<<dp[i]<<" ";
    }
    cout<<nl;
    return len;
}

void solve(){
    int n;
    cin>>n;
    int arr[n];
    loop(i, 0, n){
        cin>>arr[i];
    }
    cout<<lisBU(arr, n)<<nl;
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