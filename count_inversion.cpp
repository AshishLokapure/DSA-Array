#include<iostream>
#include<vector>
using namespace std;

void bruteForce(vector<int> nums, int n){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(nums[i] > nums[j]){
                cnt++;
            }
        }
    }
    cout<<"Count : "<<cnt;
}

int count = 0;

void merge(vector<int>& arr, int low, int mid, int high) {
    // Create temp arrays
    vector<int> temp;
    int left = low, right = mid + 1;

    // Merge two sorted halves
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]){
            temp.push_back(arr[left++]);
        } else {
            temp.push_back(arr[right]);
            count += (mid - left + 1);
            right++;
        }
    }

    // Copy remaining elements from left half
    while (left <= mid)
        temp.push_back(arr[left++]);

    // Copy remaining elements from right half
    while (right <= high)
        temp.push_back(arr[right++]);

    // Copy sorted elements back to original array
    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];
}

    // Recursive merge sort function
void mergeSort(vector<int>& arr, int low, int high) {
    if (low >= high)
        return;

    // Find the middle index
    int mid = (low + high) / 2;

    // Recursively sort left half
    mergeSort(arr, low, mid);

    // Recursively sort right half
    mergeSort(arr, mid + 1, high);

    // Merge the two sorted halves
    merge(arr, low, mid, high);
}

void optimal(vector<int> nums, int n){
    mergeSort(nums, 0, n - 1);
    cout<<"Count : "<<count;
}

int main(){
    vector<int> nums = {5, 3, 2, 4, 1};

    int n = nums.size();
    cout<<"Brute Force : "<<endl;
    bruteForce(nums, n);
    cout<<endl;

    cout<<endl<<"Optimal : "<<endl;
    optimal(nums, n);
}