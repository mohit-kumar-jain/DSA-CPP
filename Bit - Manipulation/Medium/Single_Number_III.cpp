#include<bits/stdc++.h>
using namespace std;
                   
// Brute. T.C -> O(N+M), S.C -> O(M).
// vector<int> singlenumber(vector<int>& nums) {
//     vector<int> res;
//     unordered_map<int,int> mpp;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         mpp[nums[i]]++;
//     }
//     for(auto it : mpp){
//         if(it.second == 1){
//             res.push_back(it.first);
//         }
//     }
//     return res;
// }                   

// Optimal. T.C -> O(N), S.C -> O(1).
vector<int> singlenumber(vector<int>& nums) {
    vector<int> res;
    int Xor =  0;
    for (int i = 0; i < nums.size(); i++)
    {
        Xor ^= nums[i];
    }
    int rightMostSet = (Xor & (Xor - 1)) ^ Xor;
    int b1 = 0, b2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i] & rightMostSet){
            b1 ^= nums[i];
        }
        else b2 ^= nums[i];
    }
    return {b1,b2};
}                   
                   
int main() {
    vector<int> nums = {1,2,3,1,2,3,4,5,7,8,7,8};
    vector<int> res = singlenumber(nums);
    for(int it : res)
        cout << it << " ";
    cout << endl;
    return 0;
}