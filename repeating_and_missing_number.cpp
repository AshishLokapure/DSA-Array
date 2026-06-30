#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void bruteForce(vector<int> nums, int n){
    int missing;
    int repeat;

    for(int i = 1; i <= n; i++){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(i == nums[j]){
                cnt++;
            }
        }
        if(cnt == 0){
            missing = i;
        }
        if(cnt == 2){
            repeat = i;
        }
    }
    cout<<"missing : "<<missing;
    cout<<"\nrepeat : "<<repeat;
}

void better(vector<int> nums, int n){
    int missing;
    int repeat;
    int hash[n + 1] = {0};
    for(int i = 0; i < n; i++){
        hash[nums[i]]++;
    }

    for(int i = 1; i <= n; i++){
        if(hash[i] == 0) missing = i;
        if(hash[i] == 2) repeat = i;
    }

    cout<<"missing : "<<missing;
    cout<<"\nrepeat : "<<repeat;
}

void optimal1(vector<int> nums, int n){
    long long s = 0;
    long long s2 = 0;

    long long sn = (n * (n + 1)) / 2;
    long long sn2 = (n * (n + 1) * (2 * n + 1)) / 6;

    for(int i = 0; i < n; i++){
        s += nums[i];
        s2 += (long long)nums[i] * (long long)nums[i];
    }

    long long val1 = s - sn;
    long long val2 = s2 - sn2;
    val2 = val2 / val1;

    long long y = (val1 + val2) / 2;
    long long x = y - val1;

    cout<<"missing : "<<x;
    cout<<"\nrepeat : "<<y;
}

int main(){
    vector<int> nums = {4, 3, 6, 2, 1, 1};
    int n = 6;
    
    cout<<"Array :"<<endl;
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

    cout<<"Optimal 1 : "<<endl;
    optimal1(nums, n);
    cout<<endl<<endl;
}