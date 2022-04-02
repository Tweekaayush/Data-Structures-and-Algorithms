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

void trapRainWater(int arr[], int n){
    int lmax[n];
    int rmax[n];
    int res = 0;
    lmax[0] = arr[0];
    loop(i, 1, n){
        lmax[i] = max(arr[i], lmax[i-1]);
    }
    rmax[n-1] = arr[n-1];
    for(int i = n-2; i >= 0; i--){
        rmax[i] = max(arr[i], rmax[i + 1]);
    }
    for(int i = 1; i < n-1; i++)
        res = res + (min(lmax[i], rmax[i]) - arr[i]);
    cout<<res<<" ";
}

void solve(){
    int n;
    cin>>n;
    int arr[n];
    loop(i, 0, n){
        cin>>arr[i];
    }
    trapRainWater(arr, n);
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