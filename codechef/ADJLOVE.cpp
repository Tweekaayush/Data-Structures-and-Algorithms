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
    int n, o = 0, e = 0;
    cin>>n;
    int arr[n];
    deque<int>d;
    loop(i, 0, n){
        cin>>arr[i];
        if(arr[i]%2){
            o++;
            d.push_front(arr[i]);
        }
        else{
            e ++;
            d.push_back(arr[i]);
        }
    }
    if((n == 1 and e == 1)|| o<2 ) cout<<-1;
    else if(o%2 && e == 0){
        cout<<-1;
    }
    else{
        if(o%2){
            swap(d[o-1], d[o]);
        }
        for(auto item : d){
            cout<<item<<" ";
        }
    }
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