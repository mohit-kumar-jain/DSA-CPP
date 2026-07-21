#include<bits/stdc++.h>
using namespace std;
        
// Brute. T.C -> O(2^n*K), S.C -> O(n*k).
// void subsetSum(int ind,vector<int>& nums, int n,set<int>& ds,int sum) {
//     if(n == ind){
//         ds.insert(sum);
//         return;
//     }
//     subsetSum(ind + 1,nums,n,ds,sum + nums[ind]);
//     subsetSum(ind + 1,nums,n,ds,sum);
// }                  
       
void subsetSum(int ind,vector<int>& nums, int n, vector<int>& ds,vector<vector<int>>& ans) {
    ans.push_back(ds);
    for(int i = ind; i < nums.size();i++){
        if(i != ind && nums[i] == nums[i-1]) continue;
        ds.push_back(nums[i]);
        subsetSum(i+1, nums, n, ds, ans);
        ds.pop_back();
    }
}

int main() {
    vector<int> nums = {3,1};
    int n = nums.size();
    vector<int> ds;
    vector<vector<int>> ans;
    subsetSum(0,nums,n,ds,ans);
    for(auto &ut : ans){
        for(auto &row : ut){
            cout << row << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}