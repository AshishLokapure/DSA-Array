#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<int>& nums, int n, int m, int maxAllowedpages){

    int stud = 1, pages = 0;

    for(int i = 0; i < n; i++){
        if(nums[i] > maxAllowedpages){
            return false;
        }

        if(pages + nums[i] <= maxAllowedpages){
            pages += nums[i];
        } else{
            stud++;
            pages = nums[i];
        }
    }

    return stud > m ? false : true;

}
int allocateBooks(vector<int>& nums, int n, int m){

    if(m > n) return -1;

    int sum = 0;

    for(int i = 0; i < n; i++){
        sum += nums[i];
    }

    int st = 0, end = sum;
    int mid, ans = -1;

    while(st <= end){
        mid = st + (end - st) / 2;
        if(isValid(nums, n, m, mid)){
            ans = mid;
            end = mid - 1;
        }
        else{
            st = mid + 1;
        }

    }
    return ans;
}

int main(){
    vector<int> arr = {2, 1, 3, 4};
    int n = arr.size();
    int m = 2;

    cout<<"Answer : "<<allocateBooks(arr, n, m);
    return 0;
}