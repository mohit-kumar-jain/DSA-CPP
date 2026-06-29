#include<bits/stdc++.h>
using namespace std;

// Brute. T.C -> O(n*n*n*n(log(no.of Unique triplets)),S.C -> O(2*(no.of Unique triplets)).
// vector<vector<int>> sum4(vector<int>& nums){
//     set<vector<int>> st;
//     int n = nums.size();
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i+1; j < n; j++)
//         {
//             for (int k = j+1; k < n; k++)
//             {
//                 for (int l = k+1; l < n; l++)
//                 {
//                     long long summ = (long long) nums[i] + nums[j];
//                     summ += nums[k];
//                     summ += nums[l];
//                     if(summ == 0){
//                         vector<int> res = {nums[i],nums[j],nums[k],nums[l]};
//                         sort(res.begin(),res.end());
//                         st.insert(res);
//                     }
//                 }
//             }
//         }  
//     }
//     vector<vector<int>> ans(st.begin(),st.end());
//     return ans;
// }

// Better. T.C -> O(n*n*n(log(m)),S.C -> O(2*(no.of Unique triplets))+O(m).
// vector<vector<int>> sum4(vector<int>& nums){
//     int n = nums.size();
//     vector<int> res;
//     set<vector<int>> st;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i+1; j < n; j++)
//         {
//             unordered_set<int> hashh;
//             for (int k = j+1; k < n; k++)
//             {
//                 int l = -(nums[i] + nums[j] + nums[k]);
//                 if(hashh.find(l) != hashh.end()){
//                     res = {nums[i],nums[j],nums[k],l};
//                     sort(res.begin(),res.end());
//                     st.insert(res);
//                 }
//                 hashh.insert(nums[k]);
//             }
//         } 
//     }
//     vector<vector<int>> ans(st.begin(),st.end());
//     return ans;
// }

// Optimal. T.C -> O(n*n*n),S.C -> O(1).
vector<vector<int>> sum4(vector<int>& nums,int target){
    vector<vector<int>> ans;
    vector<int> res;
    int n= nums.size();
    sort(nums.begin(),nums.end());
    for (int i = 0; i < n - 3; i++)
    {
        if(i > 0 && nums[i] == nums[i-1]) continue;
        for (int j = i + 1; j < n - 2; j++)
        {
            if(j > i+1 && nums[j] == nums[j-1]) continue;
            if ((long long)nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break ;
            if ((long long)nums[i] + nums[j] + nums[n-1] + nums[n-2] < target) continue;
            int k = j + 1;   
            int l = n - 1;
            while(k < l){
                int summ = nums[i] + nums[j] + nums[k] + nums[l];
                if(summ == target){
                    res = {nums[i],nums[j],nums[k],nums[l]};
                    k++,l--;
                    ans.push_back(res);
                    while(k < l && nums[k] == nums[k-1]) k++;
                    while(k < l && nums[l] == nums[l+1]) l--;
                }else if(summ > target){
                    l--;
                }else{
                    k++;
                }
            }
        }    
    }
    return ans;
}

int main() {
    vector<int> arr = {-1,0,1,2,-1,-4,1};
    int target = 0;
    vector<vector<int>> sol = sum4(arr,target);
    for(auto it : sol){
        for(auto num : it){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}