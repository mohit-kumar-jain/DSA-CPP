#include <bits/stdc++.h>
using namespace std;

// Brute -Force.T.C -> O(n*n) ,S.C -> O(n).
// void leadersArray(vector<int> & nums){
//     vector<int> ans;
//      int n = nums.size();
//     for (int i = 0; i < n; i++)
//     {
//         int leader = true;
//         for (int j = i+1; j < n; j++)
//         {
//             if(nums[i] <= nums[j]){
//                 leader = false;
//                 break;
//             } 
//         }
//         if(leader == true){
//             ans.push_back(nums[i])
 //         }   
//     }
//     for(auto it:ans){
//         cout<<it<<" ";
//     }
// }

// Optimal. T.C -> O(n) ,S.C -> O(1).
void leadersArray(vector<int>& nums){
    int n = nums.size();
    vector<int> ans;
    int maxi  = INT_MIN;
    for (int  i = n-1; i >= 0; i--)
    {
        if (nums[i] > maxi)
        {
            ans.push_back(nums[i]);
        }
        maxi = max(maxi,nums[i]);
    }
    for(auto it:ans){
        cout<<it<<" ";
    }
}

int main()
{
    vector <int> nums = {1,2,5,4,3};
    leadersArray(nums);
    return 0;
}