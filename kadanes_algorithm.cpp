#include<iostream>
#include<vector>
using namespace std;

// maximum sub array
int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    int n = 5, count = 0;

    for(int st = 0; st < n; st++){
        for(int end = st; end < n; end++){
            for(int i = st; i <= end; i++){
                cout<<arr[i];
            }
            cout<<" ";
            count++;
        }
        cout<<endl;
    }
    cout<<"\ntotal sub array count : "<<count;
}



// maximum sub array sum brute force
// int main(){
//     int arr[5] = {5, 2, 4, -1, -5};
//     int n = 5;
//     int maxSum = 0;

//     for(int start = 0; start < n; start++){
//         int currSum = 0;
//         for(int end = start; end < n; end++){
//             currSum += arr[end];
//             maxSum = max(currSum, maxSum);
//         }
//     }
//     cout<<"Maximum sub array sum : "<<maxSum;
// }




// optimized approach (using kadanes algo)
// int main(){
//     int arr[5] = {5, 2, 4, -1, -5};
//     int n = 5;
//     int maxSum = 0, currSum = 0; 

//     for(int i = 0; i < n; i++){
//         currSum += arr[i];
//         maxSum = max(currSum, maxSum);
//         if(currSum < 0){
//             currSum = 0;
//         }
//     }
//     cout<<"Maximum sub array sum : "<<maxSum;
// }