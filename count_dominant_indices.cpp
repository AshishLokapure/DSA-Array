#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int dominantIndices(vector<int>& nums) {

        int n = nums.size();
        int totalSum = 0;

        for(int i = 0; i < nums.size(); i++){
            totalSum += nums[i];
        }
        
        int count = 0;

        for(int i = 0; i < nums.size() - 1; i++){
            totalSum -= nums[i];
            int currAvg;
            currAvg = totalSum / (n - 1);
            n--;
            if(nums[i] > currAvg){
                count++;
            }
        }

        return count;
        
    }
};

int main(){
    vector<int> v = {4, 1, 2};
    Solution s1;
    int count = s1.dominantIndices(v);
    cout<<count;
}