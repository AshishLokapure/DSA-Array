#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<int> &nums, int &n){
    for(int i = 0; i < n; i++){
        cout<<nums[i]<<" ";
    }
}
void bubbleSort(vector<int> &nums, int &n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(nums[j] > nums[j+1]){
                swap(nums[j], nums[j+1]);
            }
        }
    }
}

void selectionSort(vector<int> &nums, int &n){
    for(int i = 0; i < n - 1; i++){
        // int smallElement = i;
        for(int j = i + 1; j < n; j++){
            if(nums[j] < nums[i]){
                // smallElement = j;
                swap(nums[i], nums[j]);

            }
        }
        // swap(nums[i], nums[smallElement]);
    }
}

void insertionSort(vector<int> &nums, int &n){
    for(int i = 1; i < n; i++){
        int curr = nums[i];
        int prev = i - 1;

        while(prev >= 0 && nums[prev] > curr){
            nums[prev + 1] = nums[prev];
            prev--;
        }
        nums[prev + 1] = curr;
    }
}

int main(){
    vector<int> nums = {4, 2, 6, 8, 1};
    vector<int> nums1 = {3, 5, 7, 8, 2, 1, 0};
    vector<int> nums2 = {23, 45, 5, 6, 2 , 1, 57, 8};

    cout<<"bubble Sort : ";
    int n = nums.size();
    bubbleSort(nums, n);
    printArray(nums, n);

    cout<<"\nSelection Sort : ";
    int n1 = nums1.size();
    selectionSort(nums1, n1);
    printArray(nums1, n1);

    cout<<"\nInsertion Sort : ";
    int n2 = nums2.size();
    insertionSort(nums2, n2);
    printArray(nums2, n2);
}