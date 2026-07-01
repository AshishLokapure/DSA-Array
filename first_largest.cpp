#include<iostream>
#include<vector>
#include <algorithm> 
using namespace std;

void bruteForce(vector<int> nums, int n){
    sort(nums.begin(), nums.end());
    cout<<"Largest : "<<nums[n - 1];
}

void optimal(vector<int> nums, int n){
    int largest = nums[0];
    for(int i = 1; i < n; i++){
        if(nums[i] > largest){
            largest = nums[i];
        }
    }

    cout<<"Largest : "<<largest;
}

int main(){
    vector<int> nums = {7, 5, 3, 6, 7, 6, 8, 8, 9, 6, 9};
    int n = nums.size();
    cout<<"Array : ";
    for(int i=0; i<n; i++){
        cout<<nums[i]<<" ";
    }

    cout<<endl;
    cout<<"Brute force : "<<endl;
    bruteForce(nums, n);

    cout<<endl;
    cout<<"Optimal : "<<endl;
    optimal(nums, n);
}