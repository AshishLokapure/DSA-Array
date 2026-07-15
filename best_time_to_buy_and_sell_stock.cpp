#include<iostream>
#include<vector>
using namespace std;

void bruteForce(vector<int> nums, int n){
    int maxProfit = 0;
    for(int i = 0; i < n; i++){
        int currProfit = 0;
        for(int j = i + 1; j < n; j++){
            currProfit = nums[j] - nums[i];
            maxProfit = max(maxProfit, currProfit);
        }
    }
    cout<<"Max Profit : "<<maxProfit;
}

void optimal(vector<int> nums, int n){
    int maxProfit = 0;
    int mini = nums[0];
    for(int i = 1; i < n; i++){
        int currProfit = nums[i] - mini;
        maxProfit = max(maxProfit, currProfit);
        if(nums[i] < mini){
            mini = nums[i];
        }
    }
    cout<<"Max Profit : "<<maxProfit;
}

int main(){
    vector<int> nums = {7, 1, 5, 3, 6, 4};
    int n = nums.size();

    cout<<"Array : ";
    for(int i = 0; i < n; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl<<endl;

    cout<<"Brute Force : "<<endl;
    bruteForce(nums, n);
    cout<<endl<<endl;

    cout<<"Optimal : "<<endl;
    optimal(nums, n);
}