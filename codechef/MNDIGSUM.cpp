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

int bSum(int n, int b, int m){
    int res = 0;
    while(n){
        res += (n%b)%mod;
        if(res > m)
            return res;
        n/=(b)%mod;
    }
    return res;
}

void solve(){
    int n, l, r, m = INT_MAX, idx, t;
    cin>>n>>l>>r;
    if(l >= n || (l<n and n<=r))
        cout<<n<<nl;
    else{
    looprev(i, r, l){   
        int temp = bSum(n, i, m);     
        if(m > temp){
            m = temp;
            idx = i;
        }
    }
    cout<<idx<<nl;
    }
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