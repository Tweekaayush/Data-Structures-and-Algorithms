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

void merge(int *arr, int start, int end, int m){
    int i = start, j = m + 1, k = 0;
    int *result = new int[end - start + 1]();
    while(i <= m && j <= end){
        if(arr[i] < arr[j])
            result[k++] = arr[i++];
        else
            result[k++] = arr[j++];
    }
    while(i <= m){
        result[k++] = arr[i++];
    }
    while(j <= end){
        result[k++] = arr[j++];
    }
    k = 0;
    for(int i = start; i <= end; i++){
        arr[i] = result[k];
        k++;
    }
    delete [] result;
}

void mergesort(int *arr, int start, int end){
    if(start >= end) return;
    int m = mid(start, end);
    mergesort(arr, start, m);
    mergesort(arr, m + 1, end);
    merge(arr, start, end, m);
}

void solve(){
    int n;
    cin>>n;
    int *arr = new int[n];
    loop(i, 0, n){
        cin>>arr[i];
    }
    mergesort(arr, 0, n - 1);
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