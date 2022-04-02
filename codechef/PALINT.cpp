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
    int n, k, key, maxV = INT_MIN, c = 0, res = INT_MAX;
    cin>>n>>k;
    int arr[n];
    map<int, int> m;
    map<int, int> ar;
    loop(i, 0, n){
        cin>>arr[i];
        m[arr[i]]++;
        ar[arr[i]]++;
    }
    loop(i, 0, n){
        int t = arr[i] ^ k;
        if(m.find(t) != m.end() and t!=arr[i])
            m[t]++;
    }
    for(auto i: m){
        maxV = max(maxV, i.ss);
    }
    for(auto i: m){
        if(i.ss == maxV){
            res = min(res, (i.ss - ar[i.ff]));
        }
    }
    cout<<maxV<<" "<<res<<nl;
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