#include<iostream>
#include<vector>
#include<set>
#include<algorithm> 
#include<climits>
using namespace std;

void fourSumBruteForce(vector<int> nums, int n, int target){
    set<vector<int>> st;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                for(int l = k + 1; l < n; l++){
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum == target){
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
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

void fourSumBetter(vector<int> nums, int n, int target){
    set<vector<int>> st;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            set<int> hashset;
            for(int k = j + 1; k < n; k++){
                int toFind = target - nums[i] - nums[j] - nums[k];
                if(hashset.find(toFind) != hashset.end()){
                    vector<int> temp = {nums[i], nums[j], nums[k], toFind};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[k]);
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

void fourSumOptimal(vector<int> nums, int n, int target){
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for(int i = 0; i < n; i++){
        if(i > 0 && nums[i] == nums[i - 1]) continue;
        for(int j = i + 1; j < n; j++){
            if(j > i + 1 && nums[j] == nums[j - 1]) continue;
            int k = j + 1;
            int l = n - 1;
            while(k < l){
                int sum = nums[i] + nums[j];
                sum += nums[k];
                sum += nums[l];
                if(sum == target){
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k < l && nums[k] == nums[k - 1]) k++;
                    while(k < l && nums[l] == nums[l + 1]) l--;
                } else if(sum < 0){
                    k++;
                } else {
                    l--;
                }
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
    int target = 0;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    cout<<"Array : "<<endl;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    cout<<"4 Sum By Brute force : "<<endl;
    fourSumBruteForce(nums, n, target);
    cout<<endl;

    cout<<"4 Sum by Better : "<<endl;
    fourSumBetter(nums, n, target);
    cout<<endl;

    cout<<"4 Sum by optimal : "<<endl;
    fourSumOptimal(nums, n, target);
}