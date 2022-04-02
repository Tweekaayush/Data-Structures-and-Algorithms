#include<bits/stdc++.h>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t,n,m,q,i;
    cin>>t;
    while(t--){
        cin>>n>>m>>q;
        int f=0,k=0;
        int mp[100001];
        for(i=0; i<100001; i++){
            mp[i]=0;
        }
        while(q--){
            char c;
            int p;
            cin>>c>>p;
            if(f==0){
                if(c=='+'){
                    k++;
                    mp[p]=1;
                }
                else if(c=='-'){
                    if(mp[p]==0){
                        f=1;
                    }else{
                        mp[p]=0;
                        k--;
                    }
                }
                if(k>m){
                    f=1;
                }
            }
        }
        if(f==1){
            cout<<"Inconsistent\n";
        }else{
            cout<<"Consistent\n";
        }
        
    }
}