#include<bits/stdc++.h>
using namespace std;

// Brute. T.C -> O(n*n*n*(log(no.of Unique triplets)),S.C -> O(2*(no.of Unique triplets)).
// vector<vector<int>> sum3(vector<int> nums){
//     set<vector<int>> st;
//     int n = nums.size();
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i+1; j < n; j++)
//         {
//             for (int k = j+1; k < n; k++)
//             {
//                 if(nums[i]+nums[j]+nums[k] == 0){
//                     vector<int> temp = {nums[i],nums[j],nums[k]};
//                     sort(temp.begin(),temp.end());
//                     st.insert(temp);
//                 }
//             }
//         } 
//     }
//     vector<vector<int>> ans(st.begin(),st.end());
//     return ans;
// }

// Better. T.C -> O(n*n*(log(no.of Unique triplets)),S.C -> O(n)+ O(2*(no.of Unique triplets)).
// vector<vector<int>> sum3(vector<int> nums){
//     int n = nums.size();
//     set<vector<int>> st;
//     for (int i = 0; i < n; i++)
//     {
//         set<int> hashhh;
//         for (int j = i+1; j < n; j++)
//         {
//             int k = -(nums[i]+nums[j]);
//             if(hashhh.find(k) != hashhh.end()){
//                 vector<int> temp = {nums[i],nums[j],k};
//                 sort(temp.begin(),temp.end());
//                 st.insert(temp);
//             }
//             hashhh.insert(nums[j]);
//         }
//     }
//     vector<vector<int>> ans(st.begin(),st.end());  
//     return ans;
// }

// Optimal. T.C -> O(n*n)+O(nlogn), S.C -> O(1).
vector<vector<int>> sum3(vector<int> nums){
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if(i>0 && nums[i] == nums[i-1]) continue;
        int j = i+1;
        int k = n-1;
        while(j<k)
        {
            int sum = nums[i] + nums[j];
            sum += nums[k];
            if(sum == 0){
                vector<int> res = {nums[i],nums[j],nums[k]};
                ans.push_back(res);
                j++;
                k--;
                while(nums[j] == nums[j-1]) j++;
                while(nums[k] == nums[k-1]) k++;
                }
                else if(sum > 0){
                k--;
            }else{
                j++;
            }
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {-1,0,1,2,-1,-4};
    vector<vector<int>> sol = sum3(arr);
    for(auto it : sol){
        for(auto num : it){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}