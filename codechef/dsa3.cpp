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
    int n,b =0, a = 0, res = 0, cur = 0, p = 0;
    cin>>n;
    string str;
    cin>>str;
    for(int i = 0; i < str.length();i++){
        if(str[i] == 'R'){
            a++;
        }
        else{
            if(p == 0){
                p = 1;
                res = max(res, a+b+1);
                b = a;
                a = 0;
            }
            else{
                if(str[i-1] == 'R'){
                    res = max(res, a + b + 1);
                    b = a;
                    a = 0;
                }
                else{
                    b = 0;
                    p = 1;
                    a = 0;
                }
            }
        }
    }
    if(str[str.length()-1] == 'R'){
        res = max(res, a + b + p);
    }
    cout<<res;
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