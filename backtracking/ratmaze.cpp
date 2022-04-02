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
int totpath = 0;

int isSafe(int i, int j, int n, vector<vector<bool>>&vis){
    return i>=0 and j>=0 and i < n and j< n and vis[i][j] == false;
}

void backFunc(int i, int j, vector<vector <int>> &grid, int n, vector<vector<bool>>&vis){
    if(i == n-1 and j == n-1)
    {
        totpath ++;
        return;
    }
    if(!isSafe(i, j, n, vis)){
        return;
    }
    vis[i][j] = true;
    if(i + 1 < n and grid[i+1][j] == 0)
        backFunc(i + 1, j, grid,n, vis);
    if(i - 1 >=0  and grid[i-1][j] == 0)
        backFunc(i - 1, j, grid,n, vis);
    if(j + 1 < n and grid[i][j+1] == 0)
        backFunc(i, j + 1, grid,n, vis);
    if(j - 1 >=0 and grid[i][j-1] == 0)
        backFunc(i, j - 1, grid,n, vis);
    vis[i][j] = false;
    return;

}

void checkPath(vector<vector<int>> &grid, int n){
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    backFunc(0, 0, grid, n, vis);
}
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> grid(n, vi(n, 0));
    loop(i, 0, n){
        loop(j, 0, n){
            cin>>grid[i][j];
        }
    }
    checkPath(grid, n);
    cout<<totpath<<nl;
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