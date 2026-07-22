#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<climits>
using namespace std;

//brute force
void majority_ele_BF(vector<int> nums, int n){
    vector<int> ans_BF;
    int idx = 0;
    for(int i = 0; i < n; i++){
        if(ans_BF.size() == 0 || ans_BF[0] != nums[i]){ 
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(nums[i] == nums[j]) cnt++;
            } 
            if(cnt >= n / 3) {
                ans_BF.push_back(nums[i]);
            }  
        }
        if(ans_BF.size() == 2) break;
    }
    for(int i = 0; i < ans_BF.size(); i++){
        cout<<ans_BF[i]<<" ";
    }
}


// better approach
void majority_ele_Better(vector<int> nums, int n){
    vector<int> ans_better;
    map<int, int> mpp;
    for(int i = 0; i < n; i++){
        mpp[nums[i]]++;
    }
    for(auto it : mpp){
        if(it.second > n / 3){
            ans_better.push_back(it.first);
        }
        if(ans_better.size() == 2) break;    
    }
    for(int i = 0; i < ans_better.size(); i++){
        cout<<ans_better[i]<<" ";
    }
}

// most optimal solution using moores voting algorithm
void majority_ele_Optimal(vector<int> nums, int n){
    vector<int> ans_optimal;
    int cnt1 = 0;
    int cnt2 = 0;
    int ele1 = INT_MIN;
    int ele2 = INT_MIN;
    for(int i = 0; i < n; i++){
        if(cnt1 == 0 && nums[i] != ele2) {
            cnt1 = 1;
            ele1 = nums[i]; 
        }
        else if(cnt2 == 0 && nums[i] != ele1) {
            cnt2 = 1;
            ele2 = nums[i];
        }
        else if(nums[i] == ele1) cnt1++;
        else if(nums[i] == ele2) cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }
    int mini = n / 3;
    cnt1 = 0;
    cnt2 = 0;
    for(int i = 0; i < n; i++){
        if(nums[i] == ele1) cnt1++;
        else if(nums[i] == ele2) cnt2++;
    }
    if(cnt1 > mini) ans_optimal.push_back(ele1);
    if(cnt2 > mini) ans_optimal.push_back(ele2);
    for(int i = 0; i < ans_optimal.size(); i++){
        cout<<ans_optimal[i]<<" ";
    }
}

int main(){
    vector<int> v = {1, 2};
    int n = v.size();

    cout<<"\nMajority Element by brute force approach : "<<endl;
    majority_ele_BF(v, n);

    cout<<"\nMajority Element by better approach than brute force : "<<endl;
    majority_ele_Better(v, n);

    cout<<"\nMajority Element by optimal approach than better approach : "<<endl;
    majority_ele_Optimal(v, n);
}