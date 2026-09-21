#include<bits/stdc++.h>
using namespace std;

// Brute. T>C -> O(N+sizdeOF(map)), S.C -> O(sizeOf(map)).
// int singleNumber(vector<int>& nums) {
//     unordered_map<int,int> mpp;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         mpp[nums[i]]++;
//     }
//     for(auto it : mpp){
//         if(it.second == 1){
//             return it.first;
//         }
//     }
//     return -1;
// }
    
//  Better. T.C -> O(N * 32), S.C -> O(1).
// int singleNumber(vector<int>& nums) {
//     int ans = 0;
//     for (int i = 0; i < 32; i++)
//     {
//         int cnt = 0;
//         for (int j = 0; j < nums.size(); j++)
//         {
//             if(nums[j] & (1 << i)){
//                 cnt++;
//             }
//         }
//         if(cnt % 3 == 1) {
//             ans = ans | (1 << i);
//         }
//     }
//     return ans;
// }

//  Better. T.C -> O(N * log N), S.C -> O(1).
// int singleNumber(vector<int>& nums) {
//     sort(nums.begin(), nums.end());
//     for (int i = 0; i < nums.size(); i += 3)
//     {
//         if(nums[i] != nums[i+2]){
//             return nums[i];
//         }
//     }
//     return -1;
// }

// Optimal. T.C -> O(N), S.C -> O(1).
int singleNumber(vector<int>& nums) {
    int ones = 0, twos = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        ones = (nums[i] ^ ones) & (~twos);
        twos = (nums[i] ^ twos) & (~ones);
    }
    return ones;
}      

   
int main() {
    vector<int> nums = {1, 0, 3, 0, 1, 1, 3, 3, 10, 0};
    cout << singleNumber(nums) << endl;
    return 0;
}