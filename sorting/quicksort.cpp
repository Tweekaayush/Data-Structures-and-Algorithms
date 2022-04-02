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
#define mid(l, r) l + (r- l)/2
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cout << *it << " = " << a << std::endl;
    err(++it, args...);
}

int partition(vi &arr, int l, int r){
    int m = l;
    int pivot = r;
    loop(i, l, r){
        if(arr[i] < arr[pivot]){
            swap(arr[i], arr[m]);
            m++;
        }
    }
    swap(arr[pivot], arr[m]);
    return m;
}

int randomPivotAlgo(vector<int>&arr, int l, int r){
    int n = rand();
    int pivot = l + (n %(r-l+1));
    swap(arr[pivot], arr[r]);
    return partition(arr, l, r);
}

void quickSort(vi &arr, int l, int r){
    if(l < r){
        int pivot_index = randomPivotAlgo(arr, l, r);
        quickSort(arr, l, pivot_index-1);
        quickSort(arr, pivot_index+1, r);
    }
}
void solve(){
    int n;
    cin>>n;
    vi arr(n);
    loop(i, 0, n){
        cin>>arr[i];
    }
    quickSort(arr, 0, n - 1);
    loop(i, 0, n){
        cout<<arr[i]<<" ";
    }
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