#include <bits/stdc++.h>
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

// Optimal. T.C -> O(N), S.C -> O(1).
int singleNumber(vector<int> &nums)
{
    int Xor = 0;
    for(int i = 0; i < nums.size(); i++) {
        Xor ^= nums[i];
    }
    return Xor;
}

int main()
{
    vector<int> num = {1, 0, 1, 0, 2};
    cout << singleNumber(num) << endl;
    return 0;
}