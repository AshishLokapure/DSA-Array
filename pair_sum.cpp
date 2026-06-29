#include<iostream>
#include<vector>
using namespace std;

class demo{
    public:
    void totalPairs(vector<int> nums){
        int count = 1;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                cout<<"Pair "<<count<<" :  "<<nums[i]<<" "<<nums[j]<<endl;
                count++;
            }

        }
    }

    //brute force approach
    vector<int> pairSumBF(vector<int> nums, int target){
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
    }


    vector<int> pairSumOS(vector<int> nums, int target){
        vector<int> ans;
        int i = 0, j = nums.size()-1;
        int sum;

        while(i < j){
            sum = nums[i] + nums[j];
            if(sum == target){
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
            else if(sum > target){
                j--;
            }
            else{
                i++;
            }
        }
    }
};
int main(){
    vector<int> v = {2, 4, 6, 11, 13};
    int size = 5;
    int target = 10;

    demo d1;
    d1.totalPairs(v);
    vector<int> ansBF = d1.pairSumBF(v, target);  //BF = brute force
    cout<<"\n(using brute force)index of pair having sum "<<target<<" : "<<ansBF[0]<<" "<<ansBF[1];

    vector<int> ansOS = d1.pairSumOS(v, target);
    cout<<"\n(using optimal)index of pair having sum "<<target<<" : "<<ansOS[0]<<" "<<ansOS[1];
    return 0;
}