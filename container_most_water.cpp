#include<iostream>
#include<vector>
using namespace std;

int brute_approach(vector<int> water){
    int area;
    int ans = 0;
    for(int i = 0; i < water.size(); i++){
        for(int j = i+1; j < water.size(); j++){
            int width = j - i;
            int height = min(water[i], water[j]);
            area = width * height;
            ans = max(ans, area);
        }
    }
    return ans;
}

int optimal_approach(vector<int> water){
    int area;
    int ans = 0;

    int i = 0;
    int j = water.size() - 1;

    while(i < j){
        int width = j - i;
        int height = min(water[i], water[j]);
        area = width * height;
        ans = max(ans, area);
        if(height == water[i]){
            i++;
        }
        else{
            j--;
        }
    }

    return ans;
    

}

int main(){
    vector<int> water = {1,8,6,2,5,4,8,3,7};

    int brute = brute_approach(water);
    cout<<"\nAnswer by brute force approach : "<<brute;

    int optimal = optimal_approach(water);
    cout<<"\nAnswer by optimal approach : "<<optimal;

}