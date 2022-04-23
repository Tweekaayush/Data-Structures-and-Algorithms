#include<bits/stdc++.h>
using namespace std;

#define ff first 
#define ss second 
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
    int n, res = 0;
    cin>>n;
    string str;
    cin>>str;
    queue<int>ind;
    for(int i = 0; i < n; i++){
        if(str[i] == '1')
            ind.push(i);
    }
    if(ind.empty()) {cout<<0<<nl;return;}
    while(!ind.empty()){
        int temp = ind.front();
        ind.pop();
        int s = ind.size();
        while(s--){
            int n = ind.front();
            ind.pop();
            if(n-temp > 1){
                temp = n;
            }
            else{
                ind.push(n);
            }
        }
        res ++;
    }
    cout<<res<<nl;
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