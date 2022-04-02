#include<iostream>
using namespace std;

int gcd(int a, int b){
    if(a == 0)
        return b;
    return gcd(b%a, a);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int a,b;
    cin>>a>>b;
    cout<<gcd(a, b);
    return 0;
}