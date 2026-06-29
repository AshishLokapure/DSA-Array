#include<iostream>
#include<vector>
using namespace std;

vector<int> maxSubArray(vector<int> nums){
    int n = nums.size();

    for(int st = 0; st < n; st++){
        for(int end = st+1; end < n; end++){
            for(int i = st; i <= end; i++){
                cout<<nums[i];
            }
            cout<<" ";
        }
        cout<<endl;
    }
}

int maxProductBF(vector<int> nums){
    int n = nums.size();

    int maxProduct = 1;
    for(int i = 0; i < n; i++){
        int currProduct = 1;
        for(int j = i; j < n; j++){
            currProduct *= nums[j];
            maxProduct = max(currProduct, maxProduct);
        }
    }
    return maxProduct;
}

int maxProductOA(vector<int> nums){
    int maxProduct = 1;
    int currProduct = 1;

    for(int i = 0; i < nums.size(); i++){
        currProduct *= nums[i];
        maxProduct = max(currProduct, maxProduct);
        if(currProduct < 0){
            currProduct = 1;
        }
    }
    return maxProduct;
}

int main(){
    vector<int> nums = {-2, 0, -1};

    cout<<"\nmaximum possible subarray : "<<endl;
    maxSubArray(nums);

    int brute = maxProductBF(nums);
    cout<<"maximum product by brute force : "<<brute;

    int optimal = maxProductOA(nums);
    cout<<"\nmaximum product by brute force : "<<optimal;
}