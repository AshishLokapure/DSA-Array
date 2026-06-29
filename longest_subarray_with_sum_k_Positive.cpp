#include<iostream>
#include<vector>
#include<algorithm> 
#include<map>
using namespace std;

void bruteForce(vector<int> nums, int n, int k){

    int len = 0;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += nums[j];
            if(sum == k){
                len = max(len, j - i + 1);
            }
        }
    }
    cout<<"length : "<<len;
}

void better(vector<int> nums, int n, int k){
    map<long long, int> mpp;
    long long sum = 0;
    int maxLen = 0;
    for(int i = 0; i < n; i++){
        sum += nums[i];
        if(sum == k){
            maxLen = i + 1;
        }
        long long rem = sum - k;
        if(mpp.find(rem) != mpp.end()){
            int len = i - mpp[rem];
            maxLen = max(maxLen, len);
        }
        // mpp[sum] = i;
        if(mpp.find(sum) == mpp.end()){
            mpp[sum] = i;
        }
    }
    cout<<"Length : "<<maxLen;
}

void optimal(vector<int> nums, int n, int k){
    int left = 0;
    int right = 0;
    long long sum = nums[0];
    int maxLen = 0;

    while(right < n){
        if(sum == k){
            maxLen = max(maxLen, right - left + 1);
        }
        while(left <= right && sum > k){
            sum -= nums[left++];
        }
        right++;
        if(right < n) {
            sum += nums[right];
        } 
    }
    cout<<"Length : "<<maxLen;
}

int main(){
    vector<int> nums = {1, 2, 3, 1, 1, 1, 1, 3, 3};
    int k = 6;
    int n = nums.size();

    cout<<"Brute Force"<<endl;
    bruteForce(nums, n, k);

    cout<<endl;
    cout<<"Better"<<endl;
    better(nums, n, k);

    cout<<endl;
    cout<<"Optimal"<<endl;
    optimal(nums, n, k);
}