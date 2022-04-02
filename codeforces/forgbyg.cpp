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

struct stats{
    int cost;
    int dmg;
    int hel;
};

void solve(){
    int n, m, c;
    cin>>n>>c;
    vector<stats> squad(n);
    loop(i, 0, n){
        cin>>squad[i].cost>>squad[i].dmg>>squad[i].hel;
    }
    cin>>m;
    map<pair<int,int>, int> dp;
    loop(i, 0, m){
        int price = INT_MAX;
        int dps, tank;
        cin>>dps>>tank;
        if(dp.find({dps, tank}) != dp.end()){
            cout<<dp[{dps, tank}];
            continue;
        }
        dp[{dps, tank}] = -1;
        for(auto i: squad){
            if(i.cost >= price || i.cost > c)
                continue;
            int s = i.cost;
            int temp = i.dmg + i.dmg;
            while(s < price and s < c){
                temp += i.dmg;
                s += i.cost;
            }
            double vil = (double)i.hel/dps;
            double her = (double)tank/temp;
            if(her < vil)
                price = min(price, s);
        }
        if(price == INT_MAX || price > c){
            cout<<-1;
        }
        else{
        cout<<price<<" ";
        dp[{dps, tank}] = price;
        }
    }
    cout<<nl;
}

int32_t main(){
    FIO;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    solve();
    return 0;
}