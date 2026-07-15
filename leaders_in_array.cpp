#include<iostream>
#include<vector>
#include<limits>
#include<algorithm>
using namespace std;

void bruteForce(vector<int> nums, int n){
    vector<int> ans;
    for(int i = 0; i < n; i++){
        int ch = true;
        for(int j = i + 1; j < n; j++){
            if(nums[j] > nums[i]){
                ch = false;
                break;
            }
        }
        if(ch == true){
            ans.push_back(nums[i]);
        }
    }
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}

void optimal(vector<int> nums, int n){
    vector<int> ansOptimal;
    int maxi = std::numeric_limits<int>::min();
    for(int i = n - 1; i >= 0; i--){
        if(nums[i] > maxi){
            ansOptimal.push_back(nums[i]);
        }
        maxi = max(maxi, nums[i]);
    }
    for(int i = 0; i < ansOptimal.size(); i++){
        cout<<ansOptimal[i]<<" ";
    }
}

int main(){
    vector<int> nums = {10, 22, 12, 3, 0, 6};
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