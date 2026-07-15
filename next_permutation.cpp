#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void optimal(vector<int> nums, int n){
    int idx = -1;
    for(int i = n - 2; i >= 0; i--){
        if(nums[i] < nums[i + 1]){
            idx = i;
            break;
        }
    }
    for(int i = n - 1; i >= idx; i--){
        if(nums[i] > nums[idx]){
            swap(nums[i], nums[idx]);
            break;
        }
    }
    reverse(nums.begin() + idx + 1, nums.end());
    cout<<"Array : ";
    for(int i = 0; i < n; i++){
        cout<<nums[i]<<" ";
    }
}

int main(){
    vector<int> nums = {2, 1, 5, 4, 3, 0, 0};
    int n = nums.size();

    cout<<"Array : ";
    for(int i = 0; i < n; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl<<endl;

    // cout<<"Brute Force : "<<endl;
    // bruteForce(nums, n);
    // cout<<endl<<endl;

    cout<<"Optimal : "<<endl;
    optimal(nums, n);
}