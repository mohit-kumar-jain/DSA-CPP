#include<bits/stdc++.h>
using namespace std;

// Brute. T.C -> O(n*n) ,S.C -> O(1).
// int reversePairs(vector<int>& nums){
//     int n = nums.size();
//     int cnt = 0;
//     for (int  i = 0; i < n; i++)
//     {
//         for (int j = i+1; j < n; j++)
//         {
//             if(nums[i] > 2 * nums[j]){
//                 cnt++;
//             }   
//         }
//     }
//     return cnt;
// }

// Better. T.C -> O(n) ,S.C -> O(1).
int reversePairs(vector<int>& nums){
    int n = nums.size();
    int cnt = 0;
    for (int  i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(nums[i] > 2 * nums[j]){
                cnt++;
            }   
        }
    }
    return cnt;
}
int main(){
    vector<int> arr = {40,25,19,12,9,6,2};
    cout << reversePairs(arr);
    return 0;
}