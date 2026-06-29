#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//brute force
int majority_ele_BF(vector<int> nums){
    int n = nums.size()/2;
    for(int val: nums){
        int freq = 0;
        for(int ele: nums){
            if(val == ele){
                freq++;
            }
        }

        if(freq > n){
            return val;
        }
    }
}


// better approach
int majority_ele_Better(vector<int> nums){
    int freq = 1, mj_ele = nums[0];
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for(int i = 1; i < n; i++){
        if(nums[i] == nums[i-1]){
            freq++;
        }
        else{
            freq = 1;
            mj_ele = nums[i];
        }

        if(freq > n/2){
            return mj_ele;
        }
    }
    return mj_ele;
}

// most optimal solution using moores voting algorithm
int majority_ele_Optimal(vector<int> nums){
    int freq = 0, mj_ele = 0;

    for(int i = 0; i < nums.size(); i++){
        if(freq == 0){
            mj_ele = nums[i];
        }
        if(mj_ele == nums[i]){
            freq++;
        }
        else{
            freq--;
        }
    }
    return mj_ele;
}

int main(){
    vector<int> v = {1, 2, 3, 2, 2, 1, 2};
    vector<int> v1 = {4, 2, 4, 4, 1, 1, 2, 4, 3};
    vector<int> v2 = {2, 1, 1, 3, 3, 3, 4, 3, 3, 3, 1};
    int mj_ele_bf = majority_ele_BF(v);
    cout<<"\nMajority Element by brute force approach : "<<mj_ele_bf;

    int mj_ele_better = majority_ele_Better(v1);
    cout<<"\nMajority Element by better approach than brute force : "<<mj_ele_better;

    int mj_ele_optimal = majority_ele_Optimal(v2);
    cout<<"\nMajority Element by optimal approach than better approach : "<<mj_ele_optimal;

}