#include<bits/stdc++.h>
using namespace std;
                   
// T.C -> O(n! * n), S.C -> O(n+n).
// void printPermu(vector<int>& nums, vector<int>& ds,vector<vector<int>>& ans,int freq[]){
//     if(nums.size() == ds.size()){
//         for(auto it : ds) cout << it << " ";
//         cout << endl;
//         return;
//     }
//     for(int i = 0; i < nums.size(); i++){
//         if(!freq[i]){
//             ds.push_back(nums[i]);
//             freq[i] = 1;
//             printPermu(nums,ds,ans,freq);
//             freq[i] = 0;
//             ds.pop_back();
//         }
//     }
// }            

// Method 2. T.C -> O(), S.C -> O().      
void printPermu(int ind, vector<int>& nums, vector<vector<int>>& ans){
    if(nums.size() == ind){
        ans.push_back(nums);
        return;
    }
    for (int i = ind; i < nums.size(); i++)
    {
        swap(nums[ind],nums[i]);
        printPermu(ind+1, nums, ans);
        swap(nums[ind],nums[i]);
    }
}

int main() {
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans;
    // int freq[nums.size()] = {0};
    // vector<int> ds;
    printPermu(0,nums,ans);
    for(auto &it : ans){
        for (auto &row : it) {
            cout << row << " ";
        }
        cout << endl;
    }
    return 0;
}