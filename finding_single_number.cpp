#include<iostream>
#include<vector>
#include<set>
#include<algorithm> 
using namespace std;

void bruteForce(vector<int> nums, int n){
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(nums[i] == nums[j]){
                cnt++;
            }
        }
        if(cnt == 1){
            cout<<"Answer : "<<nums[i];
            break;
        }
    }
}

void better(vector<int> nums, int n){
    int maxi = nums[0];
    for(int i = 0; i < n; i++){
        if(nums[i] > maxi){
            maxi = nums[i];
        }
    }
    int hash[maxi + 1] = {0};

    for(int i = 0; i < n; i++){
        hash[nums[i]]++;
    }

    for(int i = 0; i < maxi + 1; i++){
        if(hash[i] == 1){
            cout<<"Answer : "<<i;
            break;
        }
    }
}

void optimal(vector<int> nums, int n){

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans ^= nums[i];
    }
    cout<<"Answer : "<<ans;
    
}

int main(){
    vector<int> nums = {4,4,5,3,3,2,2};
    int n = nums.size();

    cout<<"Array : "<<endl;
    for(int i = 0; i < n; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl<<endl;

    cout<<"Brute Force : "<<endl;
    bruteForce(nums, n);
    cout<<endl<<endl;

    cout<<"Better : "<<endl;
    better(nums, n);
    cout<<endl<<endl;

    cout<<"Optimal : "<<endl;
    optimal(nums, n);
}