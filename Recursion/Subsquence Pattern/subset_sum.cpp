#include<bits/stdc++.h>
using namespace std;
                   
void subsetSum(int ind, vector<int>& nums, int n, vector<int>& ds,int sum) {
    if(n == ind){
        ds.push_back(sum);
        return;
    }
    subsetSum(ind + 1, nums, n, ds, sum + nums[ind]);
    subsetSum(ind + 1, nums, n, ds, sum);
} 
                   
int main() {
    vector<int>nums = {3,1,2};
    int n = nums.size();
    vector<int> ds;
    subsetSum(0,nums,n,ds,0);
    sort(ds.begin(),ds.end());
    for(auto it : ds) cout << it << " ";
    cout << endl;
    return 0;
}