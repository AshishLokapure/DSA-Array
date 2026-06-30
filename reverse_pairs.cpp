#include<iostream>
#include<vector>
using namespace std;

void bruteForce(vector<int> nums, int n){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(nums[i] > 2 * nums[j]){
                cnt++;
            }
        }
    }
    cout<<"count : "<<cnt;
}



void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low, right = mid + 1;
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right])
            temp.push_back(arr[left++]);
        else 
            temp.push_back(arr[right++]);
    }
    while (left <= mid)
        temp.push_back(arr[left++]);
    while (right <= high)
        temp.push_back(arr[right++]);

    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];
}

long long countPairs(vector<int> nums, int low, int mid, int high){
    int right = mid + 1;
    long long cnt = 0;
    for(int i = low; i <= mid; i++){
        while (right <= high && (long long)nums[i] > 2LL * nums[right]) {
            right++;
        }
        cnt += right - (mid + 1);
    }
    return cnt;
}
long long mergeSort(vector<int>& arr, int low, int high) {
    long long cnt = 0;
    if (low >= high)
        return cnt;

    int mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid + 1, high);
    cnt += countPairs(arr, low, mid, high);
    merge(arr, low, mid, high);
    return cnt;
}
void optimal(vector<int>& nums, int n) {
    cout<<"Count : "<<mergeSort(nums, 0, nums.size() - 1);
}

int main(){
    vector<int> nums = {40, 25, 19, 12, 9, 6, 2};

    int n = nums.size();
    cout<<"Brute Force : "<<endl;
    bruteForce(nums, n);
    cout<<endl;

    cout<<endl<<"Optimal : "<<endl;
    optimal(nums, n);
}