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
    string s;
    cin>>s;
    int ab = 0, ba = 0, n;
    n = s.length();
    for(int i = 1; i< n; i++){
        if(s[i] == 'b' && s[i-1] == 'a')
            ab++;
        if(s[i] == 'a' && s[i-1] =='b')
            ba++;
    }
    if(n == 1 || ab == ba){
        cout<<s<<nl;
        return;
    }
    if(ab > ba){
        if(s[0] == 'a' and s[1] == 'b')
        s[0] = 'b';
        else if(s[n-1] == 'b' and s[n-2] == 'a')
        s[n-1] = 'a';
    }
    else if(ba > ab){
        if(s[0] == 'b' and s[1] == 'a')
        s[0] = 'a';
        else if(s[n-1] == 'a' and s[n-2] == 'b')
        s[n-1] = 'b';
    }
    cout<<s<<nl;
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