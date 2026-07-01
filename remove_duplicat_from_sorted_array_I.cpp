#include<iostream>
#include<vector>
#include<set>
#include<algorithm> 
using namespace std;

void bruteForce(vector<int> nums, int n){
    set<int> st;
    for(int i = 0; i < n; i++){
        st.insert(nums[i]);
    }
    int idx = 0;
    for(auto it : st){
        nums[idx++] = it;
    }

    cout<<"Elements : "<<idx<<endl;

    cout<<"Array : "<<endl;
    for(int i = 0; i < n; i++){
        cout<<nums[i]<<" ";
    }
}

void optimal(vector<int> nums, int n){
    int k = 1;
    for(int i = 1; i < n; i++){
        if(nums[i] != nums[i - 1]){
            nums[k++] = nums[i];
        }
    }

    cout<<"Elements : "<<k<<endl;

    cout<<"Array : "<<endl;
    for(int i = 0; i < n; i++){
        cout<<nums[i]<<" ";
    }
}

int main(){
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
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