#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;

void bruteForce(vector<int> nums, int n){
    vector<int> temp;

    for(int i = 0; i < n; i++){
        if(nums[i] != 0){
            temp.push_back(nums[i]);
        }
    }
    for(int i = 0; i < temp.size(); i++){
        nums[i] = temp[i];
    }
    for(int i = temp.size(); i < n; i++){
        nums[i] = 0;
    }

    cout<<"Array : ";
    for(int i = 0; i < n; i++){
        cout<<nums[i]<<" ";
    }
}

void optimal(vector<int> nums, int n){
    int left = 0;
    for(int right = 0; right < n; right++){
        if(nums[right] != 0){
            swap(nums[right], nums[left++]);
        }
    }
    cout<<"Array : ";
    for(int i = 0; i < n; i++){
        cout<<nums[i]<<" ";
    }
}

int main(){
    vector<int> nums = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    int n = nums.size();

    cout<<"Array : ";
    for(int i = 0; i < n; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl<<endl;

    cout<<"Brute Force : "<<endl;
    bruteForce(nums, n);
    cout<<endl<<endl;

    cout<<"optimal : "<<endl;
    optimal(nums, n);
}