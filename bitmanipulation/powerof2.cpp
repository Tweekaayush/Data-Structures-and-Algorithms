#include<iostream>
using namespace std;

int powof2(int n){
    if (n == 0)
        return 0;
    return ((n & (n - 1)) == 0);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    cout<<powof2(n);
    return 0;
}