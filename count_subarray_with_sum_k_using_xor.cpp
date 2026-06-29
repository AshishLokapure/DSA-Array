#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm> 
#include <climits>
using namespace std;

void bruteForce(vector<int> nums, int n, int target){
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int xorSum = 0;
            for(int k = i; k <= j; k++){
                xorSum ^= nums[k];
            }
            if(xorSum == target){
                count++;
            }
        }
    }
    cout<<"Count : "<<count;
}

void better(vector<int> nums, int n, int target){
    int count = 0;
    for(int i = 0; i < n; i++){
        int xorSum = 0;
        for(int j = i; j < n; j++){
            xorSum ^= nums[j];
            if(xorSum == target){
                count++;
            }
        }
    }
    cout<<"Count : "<<count;
}

void optimal(vector<int> nums, int n, int target){
    int totalXor = 0;
    int count = 0;
    unordered_map<int, int> mpp;
    mpp[0] = 1;
    for(int i = 0; i < n; i++){
        totalXor ^= nums[i];
        long long x = totalXor ^ target;
        count += mpp[x];
        mpp[totalXor]++;
    }
    cout<<"Count : "<<count;
}

int main(){
    vector<int> nums = {4, 2, 2, 6, 4};
    int n = nums.size();
    int target = 6;
    cout<<"Brute Force : "<<endl;
    bruteForce(nums, n, target);
    cout<<endl;

    cout<<endl<<"Better : "<<endl;
    better(nums, n, target);
    cout<<endl;

    cout<<endl<<"Optimal : "<<endl;
    optimal(nums, n, target);
}