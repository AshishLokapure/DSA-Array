#include<iostream>
#include<vector>
#include<algorithm> 
#include<unordered_map>
using namespace std;

void bruteForce(vector<int> nums, int n){
    sort(nums.begin(), nums.end());
    cout<<"Array : ";
    for(int i = 0; i < n; i++){
        cout<<nums[i]<<" ";
    }
}

void better(vector<int> nums, int n){
    int cnt0 = 0; 
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i = 0; i < n; i++){
        if(nums[i] == 0){
            cnt0++;
        } else if(nums[i] == 1){
            cnt1++;
        } else {
            cnt2++;
        }
    }

    for(int i = 0; i < cnt0; i++){
        nums[i] = 0;
    }
    for(int i = cnt0; i < cnt0 + cnt1; i++){
        nums[i] = 1;
    }
    for(int i = cnt0 + cnt1; i < cnt0 + cnt1 + cnt2; i++){
        nums[i] = 2;
    }

    cout<<"Array : ";
    for(int i = 0; i < n; i++){
        cout<<nums[i]<<" ";
    }
}

void optimal(vector<int> nums, int n){
    int low = 0;
    int mid = 0; 
    int high = n - 1;

    while(mid <= high){
        if(nums[mid] == 0){
            swap(nums[mid++], nums[low++]);
        } else if(nums[mid] == 1){
            mid++;
        } else {
            swap(nums[mid], nums[high--]);
        }
    }

    cout<<"Array : ";
    for(int i = 0; i < n; i++){
        cout<<nums[i]<<" ";
    }
}

int main(){
    vector<int> nums = {0, 1, 1, 2, 2, 1, 0, 0, 2, 1};
    int n = nums.size();

    cout<<"Array : ";
    for(int i = 0; i < n; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl<<endl;

    cout<<"Brute Force : "<<endl;
    bruteForce(nums, n);
    cout<<endl<<endl;

    cout<<endl<<"Better : "<<endl;
    better(nums, n);
    cout<<endl<<endl;

    cout<<endl<<"Optimal : "<<endl;
    optimal(nums, n);
}