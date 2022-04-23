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

void func(int i, int target, vi arr, int &res, int cur){
    if(i == arr.size()){
        if(target == 0){
            res = max(res, cur);
        }
        return;
    }
    if(arr[i]<=target){
        func(i, target-arr[i], arr, res, cur+1);
    }
    func(i+1, target, arr, res, cur);
}

void solve(){
    int n, target;
    cin>>n>>target;
    vi arr(n);
    loop(i, 0 , n){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    int res = 0;
    func(0, target, arr, res, 0);
    cout<<res<<nl;
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