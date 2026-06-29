#include<iostream>
#include<vector>
#include<algorithm> 
#include <climits>
using namespace std;

void bruteForce(vector<int> nums, int n){
    int maxProduct = INT_MIN;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int currProduct = 1;
            for(int k = i; k <= j; k++){
                currProduct *= nums[k];
            }
            maxProduct = max(maxProduct, currProduct);

        }
    }
    cout<<maxProduct;
}

void better(vector<int> nums, int n){
    int maxProduct = INT_MIN;
    for(int i = 0; i < n; i++){
        int currProduct = 1;
        for(int j = i; j < n; j++){
            currProduct *= nums[j];
            maxProduct = max(maxProduct, currProduct);
        }
    }
    cout<<maxProduct;
}

void optimal(vector<int> nums, int n){
    int pre = 1;
    int suf = 1;
    int ans = INT_MIN;
    for(int i = 0; i < n; i++){
        if(pre == 0) pre = 1;
        if(suf == 0) suf = 1;
        pre *= nums[i];
        suf *= nums[i];
        ans = max(ans, max(pre, suf));
    }
    cout<<"answer : "<<ans;
}

int main(){
    vector<int> nums = {-2, -2, -5, -1, 0, 9, 9, 9};
    int n = nums.size();
    cout<<"Brute Force : "<<endl;
    bruteForce(nums, n);
    cout<<endl;

    cout<<endl<<"Better : "<<endl;
    better(nums, n);
    cout<<endl;

    cout<<endl<<"Optimal : "<<endl;
    optimal(nums, n);
}