#include<iostream>
#include<vector>
#include<set>
#include<algorithm> 
using namespace std;

void bruteForce(vector<int> nums1, vector<int> nums2, int n1, int n2){
    int visited[n2] = {0};
    vector<int> intersectionArray;
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n2; j++){
            if(nums1[i] == nums2[j] && visited[j] != 1){
                intersectionArray.push_back(nums1[i]);
                visited[j] = 1;
                break;
            }
            if(nums2[j] > nums1[i]) break;
        }
    }

    cout<<"Array : ";
    for(int i = 0; i < intersectionArray.size(); i++){
        cout<<intersectionArray[i]<<" ";
    }
}

void optimal(vector<int> nums1, vector<int> nums2, int n1, int n2){
    int i = 0, j = 0;
    vector<int> intersectionArray;

    while(i < n1 && j < n2){
        if(nums1[i] < nums2[j]) {
            i++;
        } else if(nums1[i] > nums2[j]) {
            j++; 
        } else {
            intersectionArray.push_back(nums1[i]);
            i++; j++;
        }
    }

    cout<<"Array : ";
    for(int i = 0; i < intersectionArray.size(); i++){
        cout<<intersectionArray[i]<<" ";
    }
}


int main(){
    vector<int> nums1 = {1, 2, 2, 3, 3, 4, 5, 6};
    vector<int> nums2 = {2, 3, 3, 5, 6, 6, 7};
    
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