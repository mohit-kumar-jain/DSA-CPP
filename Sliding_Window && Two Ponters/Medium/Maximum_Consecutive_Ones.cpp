#include<bits/stdc++.h>
using namespace std;
          
// Brute. T.C -> O(N*N) , S.C -> O(1).
// int MaxConsecutive(vector<int>& arr,int k){
//     int n = arr.size(), maxLength = 0;
//     for (int r = 0; r < n; r++)
//     {
//         int zeros = 0;
//         for (int j = r; j < n; j++)
//         {
//             if(arr[j] == 0) zeros++;
//             if(zeros > k) break;
//             maxLength = max(maxLength, j - r + 1);
//         } 
//     }
//     return maxLength;
// }                   

// Better. T.C -> O(2N) , S.C -> O(1).
int MaxConsecutive(vector<int>& arr,int k){
    int n = arr.size(), maxLength = 0,zeros = 0, l = 0;
    for (int r = 0; r < n; r++)
    {
        if(arr[r] == 0) zeros++;
        if(zeros > k) {
            if(arr[l] == 0){
                zeros--;
            }
            l++;
        }
        maxLength = max(maxLength, r - l + 1);
    }
    return maxLength;
}                   
                   
int main() {
    vector<int> arr = {1,1,1,0,0,0,1,1,1,1};
    int k = 2;
    cout << MaxConsecutive(arr,k) << endl;
    return 0;
}