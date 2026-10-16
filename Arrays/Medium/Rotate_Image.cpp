#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>> &matrix)
{
    int edgeLength = matrix.size();

    int top = 0;
    int bottom = edgeLength - 1;

    while (top < bottom)
    {
        for (int col = 0; col < edgeLength; col++)
        {
            int temp = matrix[top][col];
            matrix[top][col] = matrix[bottom][col];
            matrix[bottom][col] = temp;
        }
        top++;
        bottom--;
    }

    for (int row = 0; row < edgeLength; row++)
    {
        for (int col = row + 1; col < edgeLength; col++)
        {
            int temp = matrix[row][col];
            matrix[row][col] = matrix[col][row];
            matrix[col][row] = temp;
        }
    }
}

void printMat(vector<vector<int>>& mat) {
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }    
}

int main()
{
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    cout << "The Original Matrix is : " << endl;
    printMat(mat);
    rotate(mat);
    cout << "The Rotated Matrix is : " << endl;
    printMat(mat);
    return 0;
}