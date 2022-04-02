#include<bits/stdc++.h>
using namespace std;

int modexp(int a, int b){
    int res = 1;
    while(b){
        if(b%2)
            res *= a;
        b = b >> 1;
        a = (a * a);
    }
    return res;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int a, b;
    cin>>a>>b;
    cout<<modexp(a, b);
    return 0;
}