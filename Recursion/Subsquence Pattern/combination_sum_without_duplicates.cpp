#include<bits/stdc++.h>
using namespace std;
 
// Brute. T.C -> O(2^n*klogn), S.C -> O(k*x).
// void combinationSums(int ind, vector<int>& arr, int target, vector<int>& ds, set<vector<int>> & ans){
//     if(ind == arr.size()) {
//         if(target == 0){
//             ans.insert(ds);
//         }
//         return;
//     }
//     if(arr[ind] <= target) {
//         ds.push_back(arr[ind]);
//         combinationSums(ind+1, arr, target - arr[ind], ds, ans);
//         ds.pop_back();
//     }
//     combinationSums(ind+1, arr, target, ds, ans);
// }

// Optimal. T.C -> O(2^n*k), S.C -> O(k*x).
void combinationSums(int ind, vector<int>& arr, int target, vector<int>& ds, vector<vector<int>> & ans){
    if(target == 0) {
        ans .push_back(ds);
        return;
    }
    for(int i = ind; i < arr.size(); i++){
        if(i > ind && arr[i] == arr[i-1]) continue;
        if(arr[i] > target) break;
        ds.push_back(arr[i]);
        combinationSums(i + 1, arr, target - arr[i], ds, ans);
        ds.pop_back();
    }
}          
                   
int main() {
    vector<int>nums = {2,2,1,1,4,3,3,5};
    int target = 3;
    sort(nums.begin(),nums.end());
    vector<int> ds;
    vector<vector<int>> ans;
    combinationSums(0,nums,target,ds,ans);
    for(auto& it : ans){
        for(auto& row : it){
            cout << row << " ";
        }
        cout << endl;
    }
    return 0;
}