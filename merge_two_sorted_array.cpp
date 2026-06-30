#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void bruteForce(vector<int> nums1, vector<int> nums2, int n, int m){
    vector<int> ans(m + n, 0);
    int i = 0;
    int j = 0;
    int idx = 0;

    while(i < n && j < m){
        if(nums1[i] <= nums2[j]){
            ans[idx++] = nums1[i++];
        } else {
            ans[idx++] = nums2[j++];
        }
    }
    while(i < n){
        ans[idx++] = nums1[i++];
    }
    while(j < m){
        ans[idx++] = nums2[j++];
    }

    for(int i = 0; i < n + m; i++){
        if(i < n){
            nums1[i] = ans[i];
        } else {
            nums2[i - n] = ans[i];
        }
    }

    for(int i = 0; i < n; i++){
        cout<<nums1[i]<<" ";
    }
    cout<<endl;
    for(int j = 0; j < m; j++){
        cout<<nums2[j]<<" ";
    }

}

void better(vector<int> nums1, vector<int> nums2, int n, int m){
    int i = n - 1;
    int j = 0;

    while(i >= 0 && j < m){
        if(nums1[i] > nums2[j]){
            swap(nums1[i--], nums2[j++]);
        } else {
            break;
        }
    }
    sort(nums1.begin(), nums1.begin() + n);
    sort(nums2.begin(), nums2.begin() + m);

    for(int i = 0; i < n; i++){
        cout<<nums1[i]<<" ";
    }
    cout<<endl;
    for(int j = 0; j < m; j++){
        cout<<nums2[j]<<" ";
    }
}

int main(){
    vector<int> nums1 = {1, 3, 5, 7};
    vector<int> nums2 = {0, 2, 6, 8, 9};
    int n = nums1.size();
    int m = nums2.size();

    cout<<"Array : "<<endl;
    for(int i = 0; i < n; i++){
        cout<<nums1[i]<<" ";
    }
    cout<<endl;
    for(int j = 0; j < m; j++){
        cout<<nums2[j]<<" ";
    }
    cout<<endl;

    cout<<"Brute Force : "<<endl;
    bruteForce(nums1, nums2, n, m);
    cout<<endl;

    cout<<"better : "<<endl;
    better(nums1, nums2, n, m);
    cout<<endl;
}