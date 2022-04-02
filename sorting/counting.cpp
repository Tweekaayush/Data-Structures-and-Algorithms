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

void countSort(int arr[], int n, int k){
    vi C(k, 0);
    vi b(n);
    loop(i, 0, n){
        C[arr[i]] ++;
    }
    loop(i, 1, k){
        C[i] += C[i-1];
    }
    // loop(i, 0, k){
    //     cout<<C[i]<<" ";
    // }
    looprev(i, n-1, 0){
        b[C[arr[i]]-1] = arr[i];
        C[arr[i]]--;
    }
    loop(i, 0, n){
        cout<<b[i]<<" ";
    }
}

void solve(){
    int n, k = 0;
    cin>>n;
    int arr[n];
    loop(i, 0,n){
        cin>>arr[i];
        k = max(k, arr[i]);
    }
    countSort(arr, n, k+1);
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