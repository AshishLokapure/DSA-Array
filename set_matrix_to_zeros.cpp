#include<iostream>
#include<vector>
#include<limits>
#include<algorithm>
using namespace std;

void setRow(vector<vector<int>> &mat, int n, int m, int i){
    for(int j = 0; j < m; j++){
        if(mat[i][j] != 0){
            mat[i][j] = -1;
        }
    }
}

void setCol(vector<vector<int>> &mat, int n, int m, int j){
    for(int i = 0; i < n; i++){
        if(mat[i][j] != 0){
            mat[i][j] = -1;
        }
    }
}

void bruteForce(vector<vector<int>> &mat, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] == 0){
                setRow(mat, n, m, i);
                setCol(mat, n, m, j);
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] == -1){
                mat[i][j] = 0;
            }
        }
    }
    cout<<"Matrix : "<<endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

void optimal(vector<vector<int>> mat, int n, int m){
    vector<int> row(n, 0);
    vector<int> col(m, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(row[i] == 1 || col[j] == 1){
                mat[i][j] = 0;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    vector<vector<int>> mat = {{1, 1, 1, 1},
                                {1, 0, 0, 1},
                                {1, 1, 0, 1}, 
                                {1, 1, 1, 1}};
    int n = mat.size();
    int m = mat[0].size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;

    cout<<"Brute Force : "<<endl;
    bruteForce(mat, n, m);
    cout<<endl<<endl;

    vector<vector<int>> mat1 = {{1, 1, 1, 1},
                                {1, 0, 0, 1},
                                {1, 1, 0, 1}, 
                                {1, 1, 1, 1}};

    cout<<"Optimal : "<<endl;
    optimal(mat1, n, m);

}