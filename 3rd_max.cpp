#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums = {2, 2, 3, 1};
    int max = nums[0];
    int i = 1;

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] > max){
            max = nums[i];
            i++;
        }
    }
    cout<<max;
}