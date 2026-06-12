#include <bits/stdc++.h>
using namespace std;

// Brute - Force. T.C -> O(m*n*(m+n)) , S.C -> 0(1)
// void setZero(vector<vector<int>>& matrix){
//     int n = matrix.size(); //rows
//     int m = matrix[0].size(); //columns
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (matrix[i][j] == 0)
//             {
//                 for (int row = 0; row < n; row++)
//                 {
//                     if (matrix[row][j] != 0)
//                     {
//                         matrix[row][j] = -1;
//                     }
//                 }
//                 for (int col = 0; col < n; col++)
//                 {
//                     if (matrix[i][col] != 0)
//                     {
//                         matrix[i][col] = -1;
//                     }
//                 }
//             }  
//         }
//     }
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if(matrix[i][j] == -1 ){
//                 matrix[i][j] = 0;
//             }
//         }  
//     }
// }

// Better. T.C -> O(m*n) , S.C -> 0(m+n)
// void setZero(vector<vector<int>>& matrix){
//     int n = matrix.size();
//     int m = matrix[0].size();
//     vector<int> row (n,0); 
//     vector<int> col (m,0); 
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if(matrix[i][j] == 0){
//                 row[i] = 1;
//                 col[j] = 1;
//             }
//         }
//     } 
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if(row[i] == 1 || col[j] == 1){
//                 matrix[i][j] = 0;
//             }
//         }
//     }
// }

// Optimal. T.C -> O(m*n) , S.C -> 0(1)

void setZero(vector<vector<int>>& matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    bool firstRowZero = false;
    bool firstColZero = false;
    for(int j = 0; j < m; j++)
    {
        if(matrix[0][j] == 0)
        {
            firstRowZero = true;
            break;
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(matrix[i][0] == 0)
        {
            firstColZero = true;
            break;
        }
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < m; j++)
        {
            if(matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < m; j++)
        {
            if(matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }
    if(firstRowZero)
    {
        for(int j = 0; j < m; j++)
        {
            matrix[0][j] = 0;
        }
    }
    if(firstColZero)
    {
        for(int i = 0; i < n; i++)
        {
            matrix[i][0] = 0;
        }
    }
}

void printMatrix(vector<vector<int>>& matrix){
    for (auto row : matrix) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int> (m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout<<endl;
    setZero(arr);
    printMatrix(arr);
    return 0;
}