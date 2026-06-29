#include<iostream>
#include<vector>
#include<set>
#include<algorithm> 
#include<climits>
using namespace std;

void threeSumBruteForce(vector<int> nums, int n){
    set<vector<int>> st;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                if(nums[i] + nums[j] + nums[k] == 0){
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    for(vector<int> v : ans){
        cout<<"[ ";
        for(int num : v){
            cout<<num<<", ";
        }
        cout<<" ], ";
    }
}

void threeSumBetter(vector<int> nums, int n){
    set<vector<int>> st;
    for(int i = 0; i < n; i++){
        set<int> hashset;
        for(int j = i + 1; j < n; j++){
            int third = -(nums[i] + nums[j]);
            if(hashset.find(third) != hashset.end()){
                vector<int> temp = {nums[i], third, nums[j]};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(nums[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    for(vector<int> v : ans){
        cout<<"[ ";
        for(int num : v){
            cout<<num<<", ";
        }
        cout<<" ], ";
    }
}

void threeSumOptimal(vector<int> nums, int n){
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for(int i = 0; i < n; i++){
        if(i > 0 && nums[i] == nums[i - 1]) continue;
        int j = i + 1;
        int k = n - 1;
        while(j < k){
            int sum = nums[i] + nums[j] + nums[k];
            if(sum == 0){
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j < k && nums[j] == nums[j - 1]) j++;
                while(j < k && nums[k] == nums[k + 1]) k--;
            } else if(sum < 0){
                j++;
           } else {
                k--;
            }
        }
    }
    for(vector<int> v : ans){
        cout<<"[ ";
        for(int num : v){
            cout<<num<<", ";
        }
        cout<<" ], ";
    }
}

int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
    cout<<"Array : "<<endl;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    cout<<"3 Sum By Brute force : "<<endl;
    threeSumBruteForce(nums, n);
    cout<<endl;

    cout<<"3 Sum by Better : "<<endl;
    threeSumBetter(nums, n);
    cout<<endl;

    cout<<"3 Sum by optimal : "<<endl;
    threeSumOptimal(nums, n);
}