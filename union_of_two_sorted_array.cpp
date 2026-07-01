#include<iostream>
#include<vector>
#include<set>
#include<algorithm> 
using namespace std;

void bruteForce(vector<int> nums1, vector<int> nums2, int n1, int n2){
    set<int> st;
    vector<int> unionArray;

    for(int i = 0; i < n1; i++){
        st.insert(nums1[i]);
    }
    for(int i = 0; i < n2; i++){
        st.insert(nums2[i]);
    }
    for(auto it : st){
        unionArray.push_back(it);
    }

    cout<<"Array : ";
    for(int i = 0; i < unionArray.size(); i++){
        cout<<unionArray[i]<<" ";
    }
}

void optimal(vector<int> nums1, vector<int> nums2, int n1, int n2){
    vector<int> unionArray;

    int i = 0, j = 0;

    while(i < n1 && j < n2){
        if(nums1[i] <= nums2[j]){
            if(unionArray.size() == 0 || unionArray.back() != nums1[i]){
                unionArray.push_back(nums1[i]);
            }
            i++;
        } else {
            if(unionArray.size() == 0 || unionArray.back() != nums2[j]){
                unionArray.push_back(nums2[j]);
            }
            j++;
        }
    }
    while(i < n1){
        if(unionArray.size() == 0 || unionArray.back() != nums1[i]){
            unionArray.push_back(nums1[i]);
        }
        i++;
    }
    while(j < n2){
        if(unionArray.size() == 0 || unionArray.back() != nums2[j]){
            unionArray.push_back(nums2[j]);
        }
        j++;
    }

    cout<<"Array : ";
    for(int i = 0; i < unionArray.size(); i++){
        cout<<unionArray[i]<<" ";
    }
}

int main(){
    vector<int> nums1 = {1, 1, 2, 3, 4, 5};
    vector<int> nums2 = {2, 3, 4, 4, 5};
    
    int n1 = nums1.size();
    int n2 = nums2.size();

    cout<<"Array 1 : ";
    for(int i = 0; i < n1; i++){
        cout<<nums1[i]<<" ";
    }
    cout<<endl;
    cout<<"Array 2 : ";
    for(int i = 0; i < n2; i++){
        cout<<nums2[i]<<" ";
    }
    cout<<endl<<endl;

    cout<<"Brute Force : "<<endl;
    bruteForce(nums1, nums2, n1, n2);
    cout<<endl<<endl;

    cout<<"optimal : "<<endl;
    optimal(nums1, nums2, n1, n2);
}
