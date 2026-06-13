#include<bits/stdc++.h>
using namespace std;

// Time Complexity -> O(m*n),Space Complexity -> O(1).
void spiralMatrix(vector<vector<int>>& matrix){
    int left = 0;
    int right = matrix[0].size() - 1;
    int top = 0;
    int bottom = matrix.size() - 1;
    vector<int> sMatrix;
    while (left <= right && top <= bottom)
    {
        for (int i = left; i <= right; i++)
        {
            sMatrix.push_back(matrix[top][i]);
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            sMatrix.push_back(matrix[i][right]);
        }
        right--;
        if(top<=bottom){
            for (int i = right; i >= left; i--)
            {
                sMatrix.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if(left<=right){
            for (int i = bottom; i >= top; i--)
            {
                sMatrix.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    for(auto row : sMatrix)
    {
      cout<< row <<" ";
    }
    cout<<endl;
    
}

int main() {
    int n;
    cin>> n;
    vector<vector<int>> arr(n,vector<int> (n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        } 
    }
    cout<<endl;
    spiralMatrix(arr);
    return 0;
}