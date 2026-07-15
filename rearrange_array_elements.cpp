#include<iostream>
#include<vector>
using namespace std;

void bruteForce(vector<int> nums, int n){
    vector<int> pos;
    vector<int> neg;
    for(int i = 0; i < n; i++){
        if(nums[i] >= 0){
            pos.push_back(nums[i]);
        } else {
            neg.push_back(nums[i]);
        }
    }
    for(int i = 0; i < n / 2; i++){
        nums[i * 2] = pos[i];
        nums[i * 2 + 1] = neg[i];
    }

    cout<<"Array : ";
    for(int i = 0; i < n; i++){
        cout<<nums[i]<<" ";
    }
}

void optimal(vector<int> nums, int n){
    vector<int> ans(n);
    int pos = 0;
    int neg = 1;
    for(int i = 0; i < n; i++){
        if(nums[i] >= 0){
            ans[pos] = nums[i];
            pos += 2;
        } else {
            ans[neg] = nums[i];
            neg += 2;
        }
    }

    cout<<"Array : ";
    for(int i = 0; i < n; i++){
        cout<<ans[i]<<" ";
    }
}

void bruteForce1(vector<int> nums, int n){
    vector<int> pos;
    vector<int> neg;
    for(int i = 0; i < n; i++){
        if(nums[i] >= 0){
            pos.push_back(nums[i]);
        } else {
            neg.push_back(nums[i]);
        }
    }
    int minSize = min(pos.size(), neg.size());
    for(int i = 0; i < minSize; i++){
        nums[i * 2] = pos[i];
        nums[i * 2 + 1] = neg[i];
    }
    int idx = minSize * 2;
    for(int i = minSize; i < pos.size(); i++){
        nums[idx++] = pos[i];
    }
    for(int i = minSize; i < neg.size(); i++){
        nums[idx++] = neg[i];
    }
    cout<<"Array : ";
    for(int i = 0; i < n; i++){
        cout<<nums[i]<<" ";
    }
}

int main(){
    vector<int> nums = {3, 1, -2, -5, 2, -4};
    int n = nums.size();

    cout<<"Array with equal positive and negative elements : ";
    for(int i = 0; i < n; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl<<endl;

    cout<<"Brute Force : "<<endl;
    bruteForce(nums, n);
    cout<<endl<<endl;

    cout<<"Optimal : "<<endl;
    optimal(nums, n);
    cout<<endl<<endl;

    vector<int> nums1 = {-4, 1, 2, 3, -3, -5, -7, -9, 4, -1};
    int n1 = nums1.size();
    cout<<"Array with equal positive and negative elements : ";
    for(int i = 0; i < n1; i++){
        cout<<nums1[i]<<" ";
    }
    cout<<endl<<endl;

    cout<<"Brute Force : "<<endl;
    bruteForce1(nums1, n1);
    cout<<endl<<endl;
}