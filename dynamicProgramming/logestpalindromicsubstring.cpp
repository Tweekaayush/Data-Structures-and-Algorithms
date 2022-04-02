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

void func(string s, string s2, int n, int m, string &s_res, string s1){
    if(n==-1 || m==-1){
        if(s1.length() > s_res.length()){
            s_res = s1;
        }
        return;
    }
        func(s, s2, n-1, m-1, s_res, s1);
    if(s[n] == s2[m]){
        s1 += s[n];
        func(s, s2, n-1, m-1, s_res, s1);
    }
    else{
        if(s1.length() > s_res.length()){
            s_res = s1;
        }
        s1 = "";
        func(s, s2, n-1, m, s_res, s1);
        func(s, s2, n, m-1, s_res, s1);
    }
}

void solve(){
    string s, s2, s_res;
    cin>>s;
    s2 = s;
    s_res = "";
    reverse(s2.begin(), s2.end());
    func(s, s2, s.length()-1, s.length()-1, s_res, "");
    cout<<s_res<<" "<<nl;
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