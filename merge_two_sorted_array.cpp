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

void optimal1(vector<int> nums1, vector<int> nums2, int n, int m){
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

void swapIfGreater(vector<int> &nums1, vector<int> &nums2, int i, int j){
    if(nums1[i] > nums2[j]){
        swap(nums1[i], nums2[j]);
    }
}

void optimal2(vector<int> nums1, vector<int> nums2, int n, int m){
    int len = n + m;
    int gap = (len / 2) + (len % 2);

    while(gap > 0){
        int i = 0;
        int j = gap;
        while(j < len){
            // nums1, nums2
            if(i < n && j >= n){
                swapIfGreater(nums1, nums2, i, j - n);
            } 
            // ṇums2
            else if(i >= n){
                swapIfGreater(nums2, nums2, i - n, j - n);
            }
            // nums1
            else {
                swapIfGreater(nums1, nums1, i, j);
            }
            i++;
            j++;
        }
        if(gap == 1) break;
        gap = (gap / 2) + (gap % 2);
    }

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

    cout<<"Optimal 1 : "<<endl;
    optimal1(nums1, nums2, n, m);
    cout<<endl;

    cout<<"Optimal 2 : "<<endl;
    optimal2(nums1, nums2, n, m);
}