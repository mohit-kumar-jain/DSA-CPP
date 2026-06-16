#include<bits/stdc++.h>
using namespace std;

// Brute. T.C -> O(n*logn) + O(2n),S.C -> O(n).
// vector<vector<int>> mergeOverlapping(vector<vector<int>> nums){
//     sort(nums.begin(),nums.end());
//     vector<vector<int>> ans;
//     int n = nums.size(); 
//     for (int i = 0; i < n; i++)
//     {
//         int start = nums[i][0];
//         int end = nums[i][1];
//         if(!ans.empty() && end <= ans.back()[1]){
//             continue;
//         }
//         for (int j = i+1; j < n; j++)
//         {
//             if(nums[j][0] <= end){
//                 end = max(end,nums[j][1]);
//             }else{
//                 break;
//             }
//         }
//         ans.push_back({start,end});
//     }
//     return ans;
// }

// Better. T.C -> O(n*logn) + O(n),S.C -> O(n).
vector<vector<int>> mergeOverlapping(vector<vector<int>> nums){
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    int n = nums.size(); 
    for (int i = 0; i < n; i++)
    {
        if(ans.empty() || nums[i][0] > ans.back()[1]){
            ans.push_back(nums[i]);
        }else{
            ans.back()[1] = max(ans.back()[1] , nums[i][1]);
        }  
    }
    return ans;
}


int main(){
    vector<vector<int>> arr = {{1,3},{2,5},{7,16},{10,12}};
    vector<vector<int>> ans = mergeOverlapping(arr);
    for(auto it : ans){
        for(auto val : it){
            cout << val << " ";
        }
        cout<<endl;
    }
    return 0;
}