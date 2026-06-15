#include<bits/stdc++.h>
using namespace std;

// Brute. T.C -> O(n*n),S.C -> O(1).
// int countSubarray(vector<int> nums,int k){
//     int n = nums.size();
//     int cnt = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int Xorr = 0;
//         for (int j = i; j < n; j++)
//         {
//             Xorr ^= nums[j];
//             if(Xorr == k){
//                 cnt++;
//             }
//         } 
//     }
//     return cnt;
// }

// Optimal. T.C -> O(n),S.C -> O(1).
int countSubarray(vector<int> nums,int k){
    int n = nums.size();
    int Xorr = 0;
    unordered_map<int,int> mpp;
    mpp[Xorr]++;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        Xorr ^= nums[i];
        int x = Xorr ^ k;
        cnt += mpp[x];
        mpp[Xorr]++;
    }
    return cnt;    
}

int main(){
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;
    cout<<countSubarray(arr,k)<<endl;
}