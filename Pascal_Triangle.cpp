#include<iostream>
#include<vector>
#include<algorithm> 
#include <climits>
using namespace std;

void findNCR(int n, int r){
    int res = 1;
    for(int i = 0; i < r; i++){
        res = res * (n - i);
        res = res / (i + 1);
    }
    cout<<"Element at row : "<<n+1<<" and col : "<<r+1<<" is : "<<res;
}

void findRow(int n){
    int ans = 1;
    cout<<ans<<" ";
    for(int i = 1; i < n; i++){
        ans = ans * (n - i);
        ans = ans / i;
        cout<<ans<<" ";
    }3
}
int main(){
    // Q1. given row and col return the element appears there
    int row = 10;
    int col = 5;
    findNCR(row - 1, col - 1); 
    cout<<endl;

    // Q2. print row when row number is given
    int n = 6;
    findRow(n);
}