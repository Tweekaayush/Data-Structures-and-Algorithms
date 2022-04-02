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

int maxArea(vi height) {
    int n = height.size(), c = 0;
    int res = 0;
    int left[n];
    int right[n];
    left[0] = height[0];
    right[n-1] = height[n-1];
    loop(i, 1, n){
       left[i] = max(height[i], left[i-1]);
    }
    looprev(i, n-2, 0){
        right[i] = max(height[i], right[i+1]);
    }
    loop(i, 1, n-1){
        res = min()
        c++;
    }
    log(c);
    return res*c;
}

void solve(){
    int n;
    cin>>n;
    vi height;
    loop(i, 0, n){
        int t;
        cin>>t;
        height.pb(t);
    }
    cout<<maxArea(height)<<nl;
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