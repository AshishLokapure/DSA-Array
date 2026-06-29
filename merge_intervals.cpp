#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm> 
#include<climits>
using namespace std;

void bruteForce(vector<vector<int>> nums, int n){
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for(int i = 0; i < n; i++){
        int start = nums[i][0];
        int end = nums[i][1];
        if(!ans.empty() && end <= ans.back()[1]){
            continue;
        }
        for(int j = i + 1; j < n; j++){
            if(nums[j][0] <= end){
                end = max(end, nums[j][1]);
            } else {
                break;
            }
        }
        ans.push_back({start, end});
    }

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < 2; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

void optimal(vector<vector<int>> nums, int n){
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    for(int i = 0; i < n; i++){
        if(ans.empty() || nums[i][0] > ans.back()[1]){
            ans.push_back(nums[i]);
        } else {
            ans.back()[1] = max(ans.back()[1], nums[i][1]);
        }
    }

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < 2; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    vector<vector<int>> nums = {
        {1, 3}, {2, 6}, {8, 9}, {9, 11}, {8, 10}, {2, 4}, {15, 18}, {16, 17}
    };

    int n = nums.size();
    cout<<"Brute Force : "<<endl;
    bruteForce(nums, n);
    cout<<endl;

    cout<<endl<<"Optimal : "<<endl;
    optimal(nums, n);
}