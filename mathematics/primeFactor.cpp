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

void primeFactors(int n){
    if(n == 1){
        cout<<"No Prime Factors";
        return;
    }
    while(n%2==0){
        cout<<2<<" ";
        n = n/2;
    }
    while(n%3==0){
        cout<<3<<" ";
        n = n/3;
    }
    for(int i = 5; i*i <= n; i+=6){
        while(n%i==0){
            cout<<i<<" ";
            n/=i;
        }
        while(n%(i+2)==0){
            cout<<i+2<<" ";
            n/=(i+2);
        }
    }
    if(n>1)
        cout<<n;
}
void solve(){
    int n;
    cin>>n;
    primeFactors(n);
    cout<<endl;
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