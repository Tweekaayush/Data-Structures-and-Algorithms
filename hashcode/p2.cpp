#include <bits/stdc++.h>
using namespace std ;
#define int long long
struct z{
	string s;
	int a,b,c,d;
};
bool comp(pair<z, vector<pair<string, int>>> x, pair<z, vector<pair<string, int>>> y)
{
    if(x.first.b == y.first.b)    return x.first.c < y.first.c;
    return x.first.b < y.first.b;
}
int32_t main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int ttt = 1 ;
    while(ttt--){
        int n, m;
        cin >> n >> m;
        map<string, map<string, int>> cc;
        for(int i = 0; i < n; i++){
            string s;int x; cin >> s >> x;
            for( int j = 0 ; j < x ; j++ ){
                string g;int y;cin >> g >> y;
                cc[s][g] = y;;
            }
        }
        vector<pair<z, vector<pair<string, int>>>> levi(m);
        for( int i = 0 ; i < m ; i++ ){
            cin >> levi[i].first.s >> levi[i].first.a >> levi[i].first.b >> levi[i].first.c >> levi[i].first.d;
            for(int j = 0; j < levi[i].first.d ; j++ )
            {
                string g;int y;cin >> g >> y;
                levi[i].second.push_back({g, y});
            }
        }
        sort(levi.begin(), levi.end(), comp);
        vector<bool> vis(m);
        bool flag = true;
        vector<pair<string, vector<string>>> ansf;
        while(flag)
        {
            vector<bool> ff;
            ff = vis;
            for(int j = 0; j < m && flag; j++){
                if(vis[j])	continue;
                bool mm = true;
                vector<string> ans;
                map<string, bool> taken;
                for(int k = 0; k < levi[j].first.d && mm; k++){
                    bool temp = false;
                    for(auto it : cc){
                        if(it.second[levi[j].second[k].first] >= levi[j].second[k].second && !taken[it.first]){
                            taken[it.first] = true;
                            temp = true;
                            ans.push_back(it.first);
                            break;
                        }
                    }
                    mm = temp;
                }
                if(mm){
                    vis[j] = true;
                    for(int i = 0; i < ans.size(); i++){
                        if(cc[ans[i]][levi[j].second[i].first] == levi[j].second[i].second)	cc[ans[i]][levi[j].second[i].first]++;
                    }
                    ansf.push_back({levi[j].first.s, ans});
                }
            }
            if(vis == ff){
                flag = false;
                break;
            }
        }
        cout << ansf.size() << '\n' ;
        for(auto it : ansf){
            cout << it.first << '\n';
            for(auto it2 : it.second)
                cout << it2 << ' ';
            cout << '\n' ;
        }
    }
    return 0;
}