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

struct time{
    int duration;
    int score;
    int bestBefore;
    int roles;
};

void solve(){
    int c, p;
    cin>>c>>p;
    map<string, vector<pair<string, int>>> contributors;
    unordered_map<string, pair<struct time,vector<pair<string, int>>>> projects;
    pair<struct time, vector<pair<string, int>>> d;
    loop(i, 0, c){
        string str;
        int s;
        cin>>str;
        cin>>s;
        vector<pair<string, int>>skills;
        loop(j, 0, s){
            pair<string, int> sk;
            string str1;
            int lvl;
            cin>>str1;
            cin>>lvl;
            sk.ff = str1;
            sk.ss = lvl;
            skills.pb(sk);
        }
        contributors.insert(mp(str, skills));
    }
    // for (auto pa: contributors) {
    //     cout<<pa.ff<<nl;
    //     for(auto k: pa.ss)
    //         cout<<k.ff<<" "<<k.ss<<nl;
    // }
    loop(i, 0, p){
        string str;
        struct time ob1;
        cin>>str;
        cin>>ob1.duration>>ob1.score>>ob1.bestBefore>>ob1.roles;
        vector<pair<string, int>>skills;
        loop(i, 0, ob1.roles){
            pair<string, int> sk;
            string str1;
            int lvl;
            cin>>str1;
            cin>>lvl;
            sk.first = str1;
            sk.second = lvl;
            skills.pb(sk);
        }
        d.ff = ob1;
        d.ss = skills;
        projects.insert(mp(str, d));
    }
    
    // for (auto pa: projects) {
    //     cout<<pa.ff<<" "<<(pa.ss).ff.duration<<" "<<(pa.ss).ff.score<<" "<<(pa.ss).ff.bestBefore<<" "<<(pa.ss).ff.roles<<" "<<nl;
    //     for(auto k: (pa.ss).ss){
    //         cout<<k.ff<<" "<<k.ss<<nl;
    //     }
    // }

    // sort(projects.begin(), projects.end());

    cout<<p<<nl;
    for( auto pa: projects){
        cout<<pa.ff<<nl;
        for(auto k: (pa.ss).ss){
            for (auto pl: contributors) {
                for(auto l: pl.ss){
                        if(k.ff == l.ff){
                            cout<<pl.ff<<" ";
                            if(l.ss <= k.ss)
                                l.ss++;
                            break;
                        }
                    }
            }
        }
        cout<<nl;
    }
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