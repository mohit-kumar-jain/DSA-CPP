#include<bits/stdc++.h>
using namespace std;

// Brute. T.C -> O(n*n) ,S.C -> O(1).
// int productSubArray(vector<int>& nums){
//     int ans = 1;
//     int n = nums.size();  
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i+1; j < n; j++)
//         {
//             if(nums[i] * nums[j] > ans){
//                 ans = nums[i] * nums[j];
//             }
//         }  
//     }
//     return ans;
// }

// Optimal. T.C -> O(n) ,S.C -> O(1).
int productSubArray(vector<int>& nums){
    int ans = INT_MIN;
    int n = nums.size();
    int pre = 1, suf = 0;
    for (int i = 0; i < n; i++)
    {
        if(pre == 0){
            pre = 1; 
        }
        if(suf == 0){
            suf = 1;
        }
        pre *= nums[i];
        suf *= nums[n-i-1];
        ans = max(ans,max(pre,suf));
    }
    return ans;
}
int main(){
    vector<int> arr = {4,6,0,10,8,1,-1};
    cout << productSubArray(arr)<<endl;
    return 0;
}