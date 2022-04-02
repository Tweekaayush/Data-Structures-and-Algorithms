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


void minVal(string N, int val, int size)
{   string res;
    int f = 0;
    if(val == 9){
        for (int i = 0; i < size; i++) {
            if (i == 1 and !f) {
                res += '0';
                f = 1;
            }
            res += N[i];
        }    
        if(!f) 
            res += '0';
    }
    else{
        for (int i = 0; i < size; i++){
            if ((N[i] - '0') > val and !f){
                res += to_string(val);
                f = 1;
            }
            res += N[i];
        }
        if(!f) 
            res += to_string(val);
    }
    cout<<res<<nl;
}

void solve(){
    int s = 0, size;
    string st;
    cin>>st;
    size = st.length();
    loop(i, 0, size){
        s+= (st[i] - '0');
    }
    s = 9 - (s%9);
    minVal(st, s, size);
}

int32_t main(){
    FIO;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t, i = 1;
    cin>>t;
    while(t--){
        cout<<"Case #"<<i<<": ";
        i++;
        solve();
    }
    return 0;
}