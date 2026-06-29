#include<iostream>
#include<vector>
using namespace std;

// TC = O(N2)
vector<int> brute_approach(vector<int> nums){
    vector<int> result;
    for(int i = 0; i < nums.size(); i++){
        int ans = 1;
        for(int j = 0; j < nums.size(); j++){
            if(i != j){
                ans *= nums[j];
            }
        }
        result.push_back(ans);
    }
    return result;
}

// TC = O(n)  SP = O(n) 
vector<int> optimal_approach(vector<int> nums){
    int n = nums.size();
    vector<int> result(n, 1);

    vector<int> prefix(n, 1);
    vector<int> suffix(n, 1);

    for(int i = 1; i < n; i++){
        prefix[i] = prefix[i-1] * nums[i-1];
    }
    cout<<"\nprefix : "<<endl;
    for(int pre: prefix){
        cout<<pre<<" ";
    }

    for(int j = n - 2; j >= 0; j--){
        suffix[j] = suffix[j+1] * nums[j+1];
    }
    cout<<"\nsuffix : "<<endl;
    for(int suf: suffix){
        cout<<suf<<" ";
    }

    for(int k = 0; k < n; k++){
        result[k] = prefix[k] * suffix[k];
    }
    return result;
}

// TC = O(n)  SP = O(1) 
vector<int> optimal_approach1(vector<int> nums){
    int n = nums.size();
    vector<int> ans(n, 1);

    for(int i = 1; i < n; i++){
        ans[i] = ans[i-1] * nums[i-1];
    }

    int suffix = 1;
    for(int i = n - 2; i >= 0; i--){
        suffix *= nums[i+1];
        ans[i] *= suffix;
    }

    return ans;
}

int main(){
    vector<int> arr = {1, 2, 3, 4};

    vector<int> brute = brute_approach(arr);
    cout<<"\nAnswer by brute force approach : ";
    for(int bru: brute){
        cout<<bru<<" ";
    }

    vector<int> optimal = optimal_approach(arr);
    cout<<"\nAnswer by optimal approach : ";
    for(int opt: optimal){
        cout<<opt<<" ";
    }

    vector<int> optimal1 = optimal_approach1(arr);
    cout<<"\nAnswer by optimal approach : ";
    for(int opt1: optimal1){
        cout<<opt1<<" ";
    }
}