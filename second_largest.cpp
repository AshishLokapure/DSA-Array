#include<iostream>
#include<vector>
#include <algorithm> 
using namespace std;

void bruteForce(vector<int> nums, int n){
    sort(nums.begin(), nums.end());
    int largest = nums[n - 1];

    for(int i = n - 2; i >= 0; i--){
        if(nums[i] != largest){
            cout<<"\nSecond Largest : "<<nums[i];
            return;
        }
    }
    cout<<"\nSecond Largest : -1";
}

void better(vector<int> nums, int n){
    int largest = nums[0];

    for(int i = 1; i < n; i++){
        if(nums[i] > largest){
            largest = nums[i];
        }
    }

    int secondLargest = -1;
    for(int i = 0; i < n; i++){
        if(nums[i] > secondLargest && nums[i] < largest){
            secondLargest = nums[i];
        }
    }
    cout<<"\nSecond Largest : "<<secondLargest;

}

void optimal(vector<int> nums, int n){
    int largest = nums[0];
    int secondLargest = -1;

    for(int i = 1; i < n; i++){
        if(nums[i] > largest){
            secondLargest = largest;
            largest = nums[i];
        }
        else if(nums[i] > secondLargest && nums[i] < largest){
            secondLargest = nums[i];
        }
    }
    cout<<"\nSecond Largest : "<<secondLargest;
}
int main(){
    vector<int> nums = {7, 5, 3, 6, 7, 6, 8, 8, 9, 6, 9};

    cout<<"Array : ";
    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }

    bruteForce(nums, nums.size());
    better(nums, nums.size());
    optimal(nums, nums.size());
}