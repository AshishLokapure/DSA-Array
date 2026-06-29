#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums1 = {2,2,4,4};
    vector<int> nums2 = {2,2,2,4,4};
    int s1 = nums1.size();
    int s2 = nums2.size();
    
    vector<int> merged(s1 + s2, 0);

    // int k = merged.size() - 1;
    // int i = s1 - 1, j = s2 - 1;

    // while(j >= 0){
    //     if(i >= 0 && nums1[i] > nums2[j]){
    //         merged[k] = nums1[i];
    //         k--;
    //         i--; 
    //     } else {
    //         merged[k] = nums2[j];
    //         j--;
    //         k--;
    //     }
    // }


    merged = sorted(nums1 + nums2);

    for(int i : merged){
        cout<<i<<" ";
    }    
}