#include<iostream>
#include<vector>
#include<algorithm> 
#include<unordered_map>
using namespace std;

void bruteForce(vector<int> nums, int target, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(nums[i] + nums[j] == target){
                cout<<"True : "<<i<<" "<<j;
                return;
            }
        }
    }
    cout<<"False : -1";
}

void better(vector<int> nums, int target, int n){
    unordered_map<int, int> mpp;

    for(int i = 0; i < n; i++){
        int check = target - nums[i];
        if(mpp.find(check) != mpp.end()){
            cout<<"True : "<<mpp[check]<<" "<<i;
            return;
        }
        mpp[nums[i]] = i;
    }
    cout<<"False : -1";
}

void optimal(vector<int> nums, int target, int n){
    unordered_map<int, int> mpp;
    for(int i = 0; i < n; i++){
        mpp[nums[i]] = i;
    }
    sort(nums.begin(), nums.end());
    int i = 0;
    int j = n - 1;
    while(i < j){
        if(nums[i] + nums[j] == target) {
            cout<<"True : "<<mpp[nums[i]]<<" "<<mpp[nums[j]];
            return;
        } else if(nums[i] + nums[j] < target) {
            i++;
        } else {
            j--;
        }
    }
    cout<<"False : -1";

}

int main(){
    vector<int> nums = {2, 6, 5, 8, 11};
    int target = 14;
    int n = nums.size();

    cout<<"Brute Force"<<endl;
    bruteForce(nums, target, n);
    cout<<endl;

    cout<<"Better"<<endl;
    better(nums, target, n);
    cout<<endl;

    cout<<"optimal"<<endl;
    optimal(nums, target, n);
}