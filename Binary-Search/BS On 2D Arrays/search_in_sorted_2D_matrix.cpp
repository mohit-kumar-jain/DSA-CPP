#include <bits/stdc++.h>
using namespace std;

// Brute. T.C -> O(m*n), S.C -> O(1).
// vector<int> searchEle(vector<vector<int>>& a,int t){
//     for (int i = 0; i < a.size(); i++)
//     {
//         for (int j = 0; j < a[0].size(); j++)
//         {
//             if(a[i][j] == t){
//                 return {i,j};
//             }
//         }
//     }
//     return {-1,-1};
// }

// Better. T.C -> O(n*logm), S.C -> O(1).
// int binarySearch(vector<int>& row,int t){
//     int low = 0,high = row.size() - 1;
//     int ans = -1;
//     while(low <= high){
//         int mid = low + (high - low) / 2;
//         if(row[mid] == t){
//             return mid;
//        }else if(row[mid] > t){
//             high = mid - 1;
//         }else{
//               low = mid + 1;
//         }
//     }
//     return -1;
// }
// vector<int> searchEle(vector<vector<int>>& a,int t){
//     for (int i = 0; i < a.size(); i++)
//     {         
//         int j = (binarySearch(a[i],t));
//         if(j != -1){
//             return {i,j};
//         }
//     }
//     return {-1,-1};
// }

// Better. T.C -> O(log(m*n)), S.C -> O(1).
vector<int> searchEle(vector<vector<int>>& a,int t){
    int n = a.size();
    int m = a[0].size();
    int row = 0,col = m-1;
    while(row < n && col >= 0){
        if(a[row][col] == t){
            return {row,col};
        }else if(a[row][col] < t){
            row++;
        }else{
            col--;
        }
    }
    return {-1,-1};
}

int main()
{
    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};
    int target = 5;
    vector<int> res = searchEle(matrix,target);
    for(auto it : res){
        cout << it << " ";
    }
}