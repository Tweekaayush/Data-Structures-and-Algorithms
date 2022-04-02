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

bool dp[100009];

int sumd(int d){
    int s = 0;
    while(d){
        int temp = d%10;
        s += temp;
        d/= 10;
    }
    return s;
}

int prod(int d){
    int s = 1;
    while(d){
        int temp = d%10;
        s *= temp;
        d/= 10;
    }
    return s;
}

void solve(){
    int l, r, c=0;
    cin>>l>>r;
    memset(dp, false, sizeof(dp));
    while(l<=r){
        if(dp[l] || l%10==0 || (l%5==0 && l%2==0)){
            dp[l] = true;
            c++;
            l++;
            continue;
        }
        int s = sumd(l);
        int p = prod(l);
        if(p%s==0){
            dp[l] = true;
            c++;
        }
        l++;
    }
    cout<<c<<nl;
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