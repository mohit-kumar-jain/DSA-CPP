#include<bits/stdc++.h>
using namespace std;
         
// Brute. T.C -> O(n*n),S.C -> O(1).
// vector<int> majorityElement(vector<int> nums){
//     int n = nums.size();
//     int maxCount = n/3;
//     vector<int> res;
//     for (int i = 0; i < n; i++)
//     {
//         if(res.size() == 0 || res[0] != nums[i]){
//             int count = 0;
//             for (int j = i; j < n; j++)
//             {
//                 if(nums[i] == nums[j]){
//                     count += 1;
//                 }
//             }
//             if (count > maxCount)
//             {
//                 res.push_back(nums[i]);
//             } 
//         }
//         if (res.size() == 2) break;
//     }
//     return res;    
// }

// Better. T.C -> O(n),S.C -> O(n).
// vector<int> majorityElement(vector<int> nums){
//     int n = nums.size();
//     unordered_map<int,int> mpp;
//     vector<int> res;
//     int mini = (int)(n/3) + 1;
//     for (int i = 0; i < n; i++)
//     {
//         mpp[nums[i]]++;
//         if (mpp[nums[i]] == mini) 
//         {
//             res.push_back(nums[i]);
//         }
//         if(res.size() == 2){
//             break;
//         }
//     }
//     return res;
// }

// Optimal. T.C -> O(n),S.C -> O(1).
vector<int> majorityElement(vector<int>& nums)
{
    int n = nums.size(); 
    int cnt1 = 0, cnt2 = 0;
    int el1 = INT_MIN, el2 = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && el2 != nums[i]) {
            cnt1 = 1;
            el1 = nums[i]; 
        }
        else if (cnt2 == 0 && el1 != nums[i]) {
            cnt2 = 1;
            el2 = nums[i]; 
        } 
        else if (nums[i] == el1) {
            cnt1++;
        } 
        else if (nums[i] == el2) {
            cnt2++; 
        } 
        else {
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0, cnt2 = 0; 
    for (int i = 0; i < n; i++) {
        if (nums[i] == el1) {
            cnt1++; 
        }
        if (nums[i] == el2) {
            cnt2++;
        }
    }
    int mini = n / 3 + 1;
    vector<int> result; 
    if (cnt1 >= mini) {
        result.push_back(el1);
    }
    if (cnt2 >= mini && el1 != el2) {
        result.push_back(el2); 
    }
    return result;
}

int main() {
    vector<int> arr = {11,11,22,33,11};
    vector<int> sol = majorityElement(arr);
    for(auto it : sol){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}