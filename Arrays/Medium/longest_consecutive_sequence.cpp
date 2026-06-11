#include<bits/stdc++.h>
using namespace std;

// Brute. T.C -> O(n*n) ,S.C -> O(1).
// bool linearSearch(vector<int> & nums,int target){
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (nums[i] == target)
//         {
//             return true;
//         }
//     }
//     return false;
// }
// int longestConsecutiveSequence(vector<int>& nums,int n){
//     if(n == 0) return 0;
//    int longest = 1;
//    for (int i = 0; i < n; i++)
//    {
//         int  count = 1;
//         int x = nums[i];
//         while (linearSearch(nums,x+1) == true)
//         {
//             count += 1;
//             x += 1;
//         }
//         longest = max(longest,count);
//    }
//    return longest;
// }

// Better. T.C -> O(n*logn) ,S.C -> O(1).
// int longestConsecutiveSequence(vector<int> & nums,int n){
//     if(n == 0) return 0;
//     sort(nums.begin(),nums.end());
//     int longest = 1;
//     int counter = 0;
//     int lastSmaller = INT_MIN;
//     for (int  i = 0; i < n; i++)
//     {
//         if (nums[i] - 1 != lastSmaller)
//         {
//             counter = 1;
//             lastSmaller = nums[i];
//         }
//         else if(nums[i] - 1 == lastSmaller){
//             counter += 1;
//             lastSmaller = nums[i];
//         }
//         longest = max(longest,counter);
//     }
//     return longest;
// }

// Optimal. T.C -> O(n) ,S.C -> O(n).
int longestConsecutiveSequence(vector<int>& nums,int n){
    if (n == 0) return 0; 
    int longest = 1; 
    unordered_set<int> st;
    for(int i = 0; i < n;i++)
        st.insert(nums[i]);
    for (auto it : st) {
        if (st.find(it - 1) == st.end()) 
        {
            int cnt = 1; 
            int x = it; 
            while (st.find(x + 1) != st.end())
            {
                x = x + 1; 
                cnt = cnt + 1; 
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0;i < n;i++)
        cin >> arr[i]; 
    cout<<longestConsecutiveSequence(arr,n)<<endl;
    return 0;
}