#include <bits/stdc++.h>
using namespace std;

// Brute. T.C -> O(m*n), S.C -> O(1).
// int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
// {
//     int cnt_max = 0;
//     int ind = -1;
//     for (int i = 0; i < n; i++)
//     {
//         int cnt1 = 0;
//         for (int j = 0; j < m; j++)
//         {
//             cnt1 += matrix[i][j];
//         }
//         if(cnt1 > cnt_max){
//             cnt_max = cnt1;
//             ind = i;
//         }
//     }
//     return ind;
// }

// Optimal. T.C -> O(n*logm), S.C -> O(1).

int lowerBound(vector<int>& row,int m,int k){
    int max_cnt = -1;
    int cnt  = 0;
    for (int i = 0; i < m; i++)
    {
        if(row[i] >= k){
            cnt++;
        }
    }
    if(cnt > max_cnt){
        max_cnt = cnt;
    }
    return cnt;
}

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int cnt_max = 0,index = -1;
    for (int i = 0; i < n; i++)
    {
        int cnt1 = lowerBound(matrix[i],m,1);
        if(cnt1 > cnt_max){
            cnt_max = cnt1;
            index = i;
        }
    }
    return index;
}

int main()
{
    vector<vector<int>> matrix = {{0, 0,0}, {0, 0, 1}, {1, 1, 1}};
    int n = 3, m = 3;
    cout << "The row with maximum no. of 1's is: " << rowWithMax1s(matrix, n, m) << endl;
}
