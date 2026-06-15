#include<bits/stdc++.h>
using namespace std;

// Brute. T.C -> O(n*n),S.C -> O(1).
// int longestSubarray(vector<int>& nums)
// {
//     int n = nums.size();
//     int maxCount = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int summ = 0;
//         for (int j = i; j < n; j++)
//         {
//             summ += nums[j];
//             if (summ == 0)
//             {
//                 maxCount = max(maxCount, j - i + 1);
//             }
//         }
//     }
//     return maxCount;
// }

// Optimal. T.C -> O(n),S.C -> O(1).
int longestSubarray(vector<int>& nums){
    int n = nums.size();
    unordered_map<int,int> hashh(n);
    int sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        if(sum == 0){
            maxLen = i + 1;
        }else
        {
            if(hashh.find(sum) != hashh.end()){
                maxLen = max(maxLen, i - hashh[sum]);
            }
            else{    
                hashh[sum] = i;
            }
        }
    }
    return maxLen;
}

int main(){
    vector<int> arr = {-1,-1,-1,0,0,1,1,1,2,3,-3,1,-2};
    cout<<longestSubarray(arr)<<endl;
}