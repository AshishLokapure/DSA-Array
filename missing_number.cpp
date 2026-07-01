#include<iostream>
#include<vector>
#include<set>
#include<algorithm> 
using namespace std;

void bruteForce(vector<int> nums, int n){
    for(int i = 1; i <= n; i++){
        int flag = 0;
        for(int j = 0; j < n - 1; j++){
            if(i == nums[j]) flag = 1;
            break;
        }
        if(flag == 0){
            cout<<"Missing Number : "<<i;
        }
    }
}

void better(vector<int> nums, int n){
    int hash[n] = {0};
    for(int i = 0; i < n - 1; i++){
        hash[nums[i]]++;
    }
    for(int i = 1; i <= n; i++){
        if(hash[i] == 0){
            cout<<"Missing Number : "<<i;
            break;       
        }
    }
}

void optimal(vector<int> nums, int n){
    int sum = (n * (n + 1)) / 2;
    int arraySum = 0;
    for(int i = 0; i < n - 1; i++){
        arraySum += nums[i];
    }
    cout<<"Missing Number : "<<sum - arraySum<<endl;

    int xor1 = 0;
    int xor2 = 0;

    for(int i = 0; i < n - 1; i++){
        xor1 ^= nums[i];
        xor2 ^= i + 1;
    }
    xor2 ^= n;
    cout<<"Missing Number : "<<(xor1 ^ xor2);

}

int main(){
    vector<int> nums = {1, 2, 4, 5};
    int n = 5;

    cout<<"Array : "<<endl;
    for(int i = 0; i < n - 1; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl<<endl;

    cout<<"Brute Force : "<<endl;
    bruteForce(nums, n);
    cout<<endl<<endl;

    cout<<"Better : "<<endl;
    better(nums, n);
    cout<<endl<<endl;

    cout<<"Optimal : "<<endl;
    optimal(nums, n);
}