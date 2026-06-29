#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<vector<int>> nums = {{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}};
    int n = nums.size();
    for(const vector<int>& row : nums){
        for(int val : row){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    int count = 1;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < nums[i].size(); j++){
            if(nums[i-1][j] < nums[i][j]){
                count++;
            }
        }
        cout<<endl;
    }

    if(count == n){
        cout<<"true";
    } else {
        cout<<"false";
    }
}