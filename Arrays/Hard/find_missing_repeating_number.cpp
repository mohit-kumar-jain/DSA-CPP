#include<bits/stdc++.h>
using namespace std;

// Brute. T.C -> O(n*n) ,S.C -> O(1).
// vector<int> findMissRepeat(vector<int>& nums){
//     vector<int>res;
//     int n = nums.size();
//     int repeating = -1;
//     int missing = -1;
//     for (int i = 1; i <= n; i++)
//     { 
//         int cnt = 0;
//         for(int j = 0;j < n;j++)
//         {
//             if(nums[j] == i){
//                 cnt++;
//             }
//         }
//         if(cnt == 2) repeating = i;
//         else if(cnt == 0) missing = i;
//         if(repeating != -1 && missing != -1) break;
//     }
//     return {repeating,missing};
// }

// Better. T.C -> O(2n) ,S.C -> O(n).
// vector<int> findMissRepeat(vector<int>& nums){
//     int n = nums.size();
//     int hashhh[n+1] = {0};
//     int repeating = -1,missing = -1;
//     for (int i = 0; i < n; i++)
//     {
//         hashhh[nums[i]]++;
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         if(hashhh[i] == 2){
//             repeating = i;
//         }else if(hashhh[i] == 0)
//         {
//             missing = i;
//         }
//         if(repeating != -1 && missing != -1){
//             break;
//         }
//     }
//     return {repeating,missing};
// }

//1. Optimal. T.C -> O(n) ,S.C -> O(1).
// vector<int> findMissRepeat(vector<int>& nums){
//     int n = nums.size();
//     int S = 0,S2 = 0;
//     int SN = (n*(n+1)) / 2;
//     int S2N = (n*(n+1)*(2*n+1)) / 6;
//     for (int i = 0; i < n; i++)
//     {
//         S += nums[i]; 
//         S2 += nums[i] * nums[i];
//     }
//     int val1 = S - SN; // X -Y
//     int val2 = S2 - S2N; // x2- Y2   
//     val2 = val2 / val1; // X + Y
//     int repeating = (val1 + val2) / 2;
//     int missing = repeating - val1;
//     return {missing,repeating};
// }

//2. Optimal . T.C -> O(n) ,S.C -> O(1).
// using Xor.
vector<int> findMissRepeat(vector<int>& nums){
    int n = nums.size();
    int xrr = 0;
    for(int i = 0; i < n; i++){
        xrr ^= nums[i];
        xrr ^= (i+1);
    }
    int bitNo = 0;
    // while(1){
    //     if(xrr & (1<<bitNo) != 0){
    //         break;
    //     }else{
    //         bitNo++;
    //     }
    // }
    
    // same as above.
    int number = xrr & ~(xrr-1);

    int zero = 0,one = 0;
    for (int i = 0; i < n; i++)
    {
        //One club
        if(nums[i] & number != 0){
            one ^= nums[i]; 
        }else{ //Zero club
            zero ^= nums[i]; 
        }
    }
    for(int i = 1;i<= n;i++){
        //One club
        if(i & number != 0){
            one ^= i; 
        }else{ //Zero club
            zero ^= i; 
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if(nums[i] == 0) cnt++;
    }
    if(cnt == 2) return {zero,one};
    return {one,zero};

}


int main(){
    vector<int> arr = {1,2,2,3,4};
    vector<int> res = findMissRepeat(arr);
    for(auto it : res){
        cout << it << " ";
    }
    return 0;
}