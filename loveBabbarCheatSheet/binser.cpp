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
int binserRe(int arr[], int l, int r, int num){
    if(l<=r){
        int m = l + (r-l)/2;
        if(arr[m] == num)
            return m;
        else if(arr[m] < num)
            return binserRe(arr, m+1, r, num);
        else 
            return binserRe(arr, l, m-1, num);
    }
    return -1;
}
int binserIt(int arr[], int r,int num){
    int l = 0;
    while(l<=r){
        int m = l + (r-l)/2;
        if(arr[m] == num)
            return m;
        else if(arr[m] < num)
            l = m+1;
        else
            r = m-1;
    }
    return -1;
}

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i <n ; i++){
        cin>>arr[i];
    }
    cout<<binserIt(arr, n-1, 15)<<nl;
    cout<<binserRe(arr, 0, n-1, 15)<<nl;
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
