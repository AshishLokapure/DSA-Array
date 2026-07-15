#include<iostream>
#include<vector>
#include<limits>
#include<unordered_set>
#include<algorithm>
using namespace std;

void bruteForce(vector<int> nums, int n){
    int maxLen = 1;
    for(int i = 0; i < n; i++){
        int currLen = 1;
        int prev = nums[i];
        for(int j = 0; j < n; j++){
            if(nums[j] == prev + 1){
                currLen++;
                prev += 1;
                j = 0;
            }
        }
        maxLen = max(currLen, maxLen);
    }
    cout<<"Max Length : "<<maxLen;
}

void better(vector<int> nums, int n){
    sort(nums.begin(), nums.end());
    int maxCount = 1;
    int currCount = 0;
    int lastEle = std::numeric_limits<int>::min();
    for(int i = 1; i < n; i++){
        if(nums[i] == lastEle) continue;
        if(nums[i] == lastEle + 1){
            currCount++;
            lastEle = nums[i];
        } else if(nums[i] != lastEle) {
            currCount = 1;
            lastEle = nums[i];
        }
        maxCount = max(currCount, maxCount);

    }
    cout<<"Max Length : "<<maxCount;
}

void optimal(vector<int> nums, int n){
    unordered_set<int> st;
    int longest = 1;
    for(int i = 0; i < n; i++){
        st.insert(nums[i]);
    }
    for(auto it : st){
        if(st.find(it - 1) == st.end()){
            int cnt = 0;
            int x = it;
            while(st.find(x) != st.end()){
                cnt++;
                x++;
            }
            longest = max(longest, cnt);
        }
    }
    cout<<"Max Length : "<<longest;
}

int main(){
    vector<int> nums = {102, 4, 100, 1, 101, 3, 2, 1, 1, 1, 1, 2, 2, 5, 5, 6};
    int n = nums.size();

    cout<<"Array : ";
    for(int i = 0; i < n; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl<<endl;

    cout<<"Brute Force : "<<endl;
    bruteForce(nums, n);
    cout<<endl<<endl;

    cout<<"Better : "<<endl;
    better(nums, n);
    cout<<endl<<endl;

    cout<<"Optimal : "<<endl;
    optimal(nums, n);
}