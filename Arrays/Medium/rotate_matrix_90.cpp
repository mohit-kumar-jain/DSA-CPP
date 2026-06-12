#include <bits/stdc++.h>
using namespace std;

// Brute - Force. T.C -> O(n*n) , S.C -> 0(n*n)
// void rotateBy90(vector<vector<int>>& matrix){
//     int n = matrix.size();
//     vector<vector<int>> rMatrix(n, vector<int>(n));
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             rMatrix[j][(n-1)-i] = matrix[i][j];
//         } 
//     }
//     for (auto row : rMatrix) {
//         for (auto val : row) {
//             cout << val << " ";
//         }
//         cout << endl;
//     }
// }

// Optimal. T.C -> O(n*n) , S.C -> 0(1).
void rotateBy90(vector<vector<int>>& matrix){
    int n = matrix.size();
    // Transpose.
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            swap(matrix[j][i],matrix[i][j]);
        }
    }
    // rotate
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(),matrix[i].end());
        
    }
    // Print result
    for(auto row : matrix){
        for(auto val : row){
            cout<<val<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int> (n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout<<endl;
    rotateBy90(arr);
    return 0;
}