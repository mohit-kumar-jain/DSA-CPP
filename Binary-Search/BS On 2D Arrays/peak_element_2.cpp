#include <bits/stdc++.h>
using namespace std;

// Brute. T.C -> O(m*n), S.C -> O(1).
// vector<int> findPeak(vector<vector<int>> a){
//     for(int i = 0; i < a.size();i++){
//         for (int j = 0; j < a[0].size(); j++)
//         {
//             if(a[i][j] > a[i+1][j] && a[i][j] > a[i-1][j-1] && a[i][j] > a[i][j-1] && a[i][j] > a[i][j+1]){
//                 return {i,j};
//             }
//         }
//     }
//     return {-1,-1};
// }

// Optimal. T.C -> O(n * logm), S.C -> O(1).
int maxColumnElement(vector<vector<int>> &a, int row)
{
    int max_val = -1;
    int ind = -1;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i][row] > max_val)
        {
            max_val = a[i][row];
            ind = i;
        }
    }
    return ind;
}

vector<int> findPeak(vector<vector<int>> a)
{
    int n = a.size(), m = a[0].size();
    int low = 0, high = m - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int row = maxColumnElement(a, mid);
        int left = mid - 1 >= 0 ? a[row][mid - 1] : -1;
        int right = mid + 1 < m ? a[row][mid + 1] : -1;
        if (a[row][mid] > left && a[row][mid] > right)
        {
            return {row, mid};
        }
        else if (left > a[row][mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return {-1, -1};
}

int main()
{
    vector<vector<int>> matrix = {{10, 20, 15}, {1, 30, 14}, {7, 16, 32}};
    vector<int> res = findPeak(matrix);
    for (auto it : res)
    {
        cout << it << " ";
    }
}