#include<iostream>
#include<vector>
#include <algorithm> 
using namespace std;

void rotatedByOne(vector<int> nums, int k){
    int temp = nums[0];

    for(int i = 0; i < nums.size(); i++){
        if(i == nums.size() - 1){
            nums[i] = temp;
        } else{
            nums[i] = nums[i+1];
        }
    }
    cout<<"\nRotated Array : ";
    for(int i = 0; i < nums.size(); i++){
        cout<<nums[i]<<" ";
    }
}

void bruteForce(vector<int> nums, int n, int k){
    vector<int> temp;

    for(int i = 0; i < k; i++){
        temp.push_back(nums[i]);
    }

    for(int i = 0; i < n - k; i++){
        nums[i] = nums[i+k];
    }
    for(int i = 0; i < k; i++){
        nums[n - k + i] = temp[i];
    }
    cout<<"\nRotated Array : ";
    for(int i = 0; i < nums.size(); i++){
        cout<<nums[i]<<" ";
    }
}

void optimal(vector<int> nums, int n, int k){
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
    reverse(nums.begin(), nums.end());  
    cout<<"\nRotated Array : ";
    for(int i = 0; i < nums.size(); i++){
        cout<<nums[i]<<" ";
    }
}


int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

    cout << "Original Array : ";
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    int k = 3;
    if(k == arr.size()){
        cout<<"\nRotated Array : ";
        for(int i = 0; i < arr.size(); i++){
            cout<<arr[i]<<" ";
        }
        return 0;
    }

    if(k > arr.size()){
        k = k % arr.size();
    }

    rotatedByOne(arr, 1);
    bruteForce(arr, arr.size(), k);
    optimal(arr, arr.size(), k);

    return 0;


}