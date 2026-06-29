#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;

int main(){

    vector<int> nums = {0,0,1,1,1,1,2,3,3};
    int k = 0;
    int i = 0;
    int j = 0;
    int n = nums.size();
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

    cout<<"i : "<<i<<endl<<"j : "<<j<<endl<<"k : "<<k<<endl;
    cout<<"Array Elements : ";

    for(int i = 0; i < k; i++){
        cout<<nums[i]<<" ";
    }
}