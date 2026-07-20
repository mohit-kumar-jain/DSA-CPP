#include<bits/stdc++.h>
using namespace std;

/*

Time Complexity: O(2t * k) due to exploring all combinations
up to the target with copying each valid combination of average length k.
Space Complexity: O(k * x) to store all valid combinations, 
where x is the number of combinations and k is their average length.

*/

void findSum(int ind, int target, vector<int>& arr,vector<vector<int>>& ans, vector<int>& ds){
    if(ind == arr.size()){
        if(target == 0){
            ans.push_back(ds);
        }
        return;
    }

    if(arr[ind] <= target){
        ds.push_back(arr[ind]);
        findSum(ind, target - arr[ind], arr, ans, ds);
        ds.pop_back();
    }
    findSum(ind+1, target, arr, ans, ds);
}

vector<vector<int>> CombinationSum(vector<int>& arr, int target){
    vector<vector<int>> ans;
    vector<int> ds;
    findSum(0,target,arr,ans,ds);
    return ans;
}                   
                   
int main() {
    vector<int> arr = {1,2,3,4,5,6};
    int target = 10;
    vector<vector<int>> res = CombinationSum(arr,target);
    for(auto &it : res){
        for(auto &row : it){
            cout << row << " ";
        }
        cout << endl;
    }
    return 0;
}