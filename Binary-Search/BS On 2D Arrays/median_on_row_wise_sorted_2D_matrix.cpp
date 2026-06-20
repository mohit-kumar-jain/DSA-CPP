#include <bits/stdc++.h>
using namespace std;

// Brute. T.C -> O(m*n*(log(m*m))), S.C -> O(m*n).
// int median(vector<vector<int>>& a){
//     int n = a.size(),m = a[0].size();
//     vector<int> b;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             b.push_back(a[i][j]);
//         }
//     }
//     sort(b.begin(),b.end());
//     return b[(m*n) / 2];
// }

// Optimal. T.C -> O(m*n*(log(m*m))), S.C -> O(1).

int countLessEqual(vector<int> &row, int mid)
{
    return upper_bound(row.begin(), row.end(), mid) - row.begin();
}
int findMedian(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int low = matrix[0][0];
    int high = matrix[0][m - 1];
    for (int i = 1; i < n; i++)
    {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][m - 1]);
    }
    while (low < high)
    {
        int mid = (low + high) / 2;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            count += countLessEqual(matrix[i], mid);
        }
        if (count < (n * m + 1) / 2)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}


int main()
{
    vector<vector<int>> matrix = {{1, 4, 9}, {2, 5, 6}, {3, 7, 8}};
    cout << findMedian(matrix);
}