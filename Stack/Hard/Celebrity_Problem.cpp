#include<bits/stdc++.h>
using namespace std;
      
// Brute. T.C -> O(N*N) + O(N), S.C -> O(N) + O(N).
// int celebrity (vector<vector<int>>& mat) {
//     int res = -1;
//     int n = mat.size();
//     vector<int> Iknow(n,0);
//     vector<int> Knowme(n,0);
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if(mat[i][j] == 1) {
//                 Knowme[j]++;
//                 Iknow[i]++;
//             }
//         }
//     }
//     for (int i = 0; i < n; i++)
//     {
//         if( (Knowme[i] == n-1) && (Iknow[i] == 0) ){
//             res = i;
//         }
//     }
//     return res;
// }                 
                   
// Optimal. T.C -> O(N), S.C -> O(1).
int celebrity (vector<vector<int>>& mat) {
    int n = mat.size();
    int top = 0, down = n -1;
    while(top < down) {
        if(mat[top][down] == 1){
            top++;
        } else if (mat[down][top] == 1) {
            down--;
        }else{
            top++;
            down--;
        }
    }
    if(top > down) return -1;
    for (int i = 0; i < n; i++)
    {
        if(i == top) continue;
        if(mat[top][i] == 1 || mat[i][top] == 0){
            return -1;
        }
    }
    return top;
}


int main() {
    vector<vector<int>> mat = { {0, 1, 1, 0}, {0, 0, 0, 0}, {1, 1, 0, 0}, {0, 1, 1, 0} };
    cout << celebrity(mat) << endl;
    return 0;
}