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
    int n, m;
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        if(i == 0){
            for(int j = 0; j < m; j++){
                if(j == 0){
                    cout<<"..+";
                }
                else cout<<"-+";
            }
            cout<<endl;
        }
        for(int j = 0; j < m; j++){
            if(i == 0 and j == 0){
                cout<<"..|";
            }
            else if(j == 0){
                cout<<"|.|";
            }
            else cout<<".|";
        }
        cout<<endl;
        for(int j = 0; j < m; j++){
            if(j==0)
            cout<<"+-+";
            else cout<<"-+";
        }
        cout<<endl;
    }
}

int32_t main(){
    FIO;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t, i = 1;
    cin>>t;
    while(t--){;
        cout<<"Case #"<<i<<":"<<nl;
        i = i + 1;
        solve();
    }
    return 0;
}