#include<iostream>
#include<vector>
#include<map>
#include<algorithm> 
using namespace std;

void bruteForce(vector<int> nums, int n){
    map<int, int> mpp;
    for(int i = 0; i < n; i++){
        mpp[nums[i]]++;
    }
    int idx = 0;
    for(auto it : mpp){
        if(it.second >= 2){
            for(int i = 0; i < 2; i++){
                nums[idx++] = it.first;
            }
        } else {
            nums[idx++] = it.first;
        }
    }

    cout<<"Elements : "<<idx<<endl;
    cout<<"Array : ";
    for(int i = 0; i < n; i++){
        cout<<nums[i]<<" ";
    }    
}

void optimal(vector<int> nums, int n){
    int k = 0;
    int i = 0;
    int j = 0;
    for(; j < n; j++){
        if(j == n - 1 && j - i > 1){
            nums[k] = nums[i];
            nums[k + 1] = nums[i];
            // k + 2;
        } else {
            nums[k] = nums[i];
            // k++;
        }

        if(nums[i] != nums[j]){
            if(j - i > 1){
                nums[k] = nums[i];
                nums[k + 1] = nums[i];
                k = k + 2;
                i = j;
            } else {
                nums[k++] = nums[i];
                i = j;
            }
        }
    }

    if(j - i > 1){
        nums[k] = nums[i];
        nums[k + 1] = nums[i];
        k += 2;
    } else {
        nums[k++] = nums[i];
    }

    cout<<"Elements : "<<i<<endl;
    cout<<"Array : ";

    for(int i = 0; i < k; i++){
        cout<<nums[i]<<" ";
    }
}

int main(){

    vector<int> nums = {0,0,1,1,1,1,2,3,3};
    int n = nums.size();

    cout<<"Array : "<<endl;
    for(int i = 0; i < n; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl<<endl;

    cout<<"Brute Force : "<<endl;
    bruteForce(nums, n);
    cout<<endl<<endl;

    cout<<"Optimal : "<<endl;
    optimal(nums, n);
}