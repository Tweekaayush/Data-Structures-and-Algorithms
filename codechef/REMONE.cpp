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

int check(vi arr, vi arr2, int n, set<int>s){
    sort(arr.begin(), arr.end());
    sort(arr2.begin(), arr2.end());
    int x1 = arr2[0] - arr[1];
    int x2 = arr2[0] - arr[0];
    if(x2 <= 0)
        return x1;
    else if(x1 <= 0)
        return x2;
    loop(i, 0, n-1){
        if(s.count(arr2[i] - x1) == 0)
        {
            return x2;
        }
    }
    return x1;
}

void solve(){
    int n;
    cin>>n;
    vi arr(n);
    vi arr2;
    set<int>s;
    loop(i, 0, n){
        cin>>arr[i];
        s.insert(arr[i]);
    }
    loop(i, 0, n-1){
        int t;
        cin>>t;
        arr2.pb(t);
    }
    cout<<check(arr, arr2, n, s)<<nl;
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