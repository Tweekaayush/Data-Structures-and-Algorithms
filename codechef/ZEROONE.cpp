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
    int n, p, k, res = 0;
    cin>>n;
    vi v1;
    vi v2;
    loop(i, 0, n){
        int temp;
        cin>>temp;
        if(i%2)
            v2.pb(temp);
        else v1.pb(temp);
    }
    sort(v1.begin(), v1.end(), greater<int>());
    sort(v2.begin(), v2.end());
    p = v1.size();
    k = v2.size();
    loop(i, 0, p){
        loop(j, i, k){
            res += v1[i]*v2[j];
        }
    }
    int i, j;
    i = 0;
    j = 0;
    while(i < p || j < k){
        if(i<p)
        cout<<v1[i]<<" ";
        if(j<k)
        cout<<v2[j]<<" ";
        i++;
        j++;
    }
    cout<<nl<<res<<nl;
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