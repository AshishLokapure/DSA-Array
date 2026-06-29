#include<iostream>
#include<vector>
#include<algorithm> 

using namespace std;

void bruteForce(vector<vector<int>> nums, int n){
    vector<vector<int>> ans(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < nums.size(); j++){
            ans[j][n - 1 - i] = nums[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < nums.size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

void optimal(vector<vector<int>> &nums, int n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int temp = nums[i][j];
            nums[i][j] = nums[j][i];
            nums[j][i] = temp;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n / 2; j++){
            swap(nums[i][j], nums[i][n - j - 1]);
        }
    }
}

int main(){
    vector<vector<int>> nums = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int n = nums.size();

    cout<<"Original Matrix : "<<endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < nums.size(); j++){
            cout<<nums[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<"Matrix After rotate (Brute Force) : "<<endl;
    bruteForce(nums, n);

    cout<<endl<<"Matrix After Rotate (Optimal) : "<<endl;
    optimal(nums, n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<nums[i][j]<<" ";
        }
        cout<<endl;
    }
}