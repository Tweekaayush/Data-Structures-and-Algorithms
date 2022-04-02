/*
Code by Aayush Dobriyal (tweek_iwnl)
Noida Institute of Engineering and Technology
*/
#include<iostream>
#include<vector>
using namespace std;

const int N = 40;

inline void sumFunc(int &sum, int n, vector<int>array){

    sum = 0;

    for(int i = 0; i < n; i++){

        sum += array[i];

    }
}

int main(){
    int sum = 0;
    vector<int>array(N);

    for(int i = 0; i < N; i++){
        array[i] = i;
    }
    sumFunc(sum, N, array);

    cout<<"sum is "<<sum<<endl;

    return 0;
}