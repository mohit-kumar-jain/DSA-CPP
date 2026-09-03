#include<bits/stdc++.h>
using namespace std;
                   
class Solution {
    public:
        // Brute. T.C -> O(N*N), S.C -> O(N).
        // vector<int> nextGreaterElements(vector<int>& nums){
        //     int n = nums.size();
        //     vector<int> res(n, -1);
        //     for (int i = 0; i < n -1; i++)
        //     {
        //         for (int j = i+1; j < n; j++)
        //         {
        //             if(nums[j] > nums[i]) {
        //                 res[i] = nums[j];
        //                 break;
        //             }
        //         }
        //     }
        //     return res;
        // }

        // Optimal. T.C -> O(N), S.C -> O(N).
        stack<int> st;
        vector<int> nextGreaterElements(vector<int>& nums){
            int n = nums.size();
            vector<int> res(n,-1);
            for(int i = n-1; i >= 0; i--) {
                while(!st.empty() && st.top() <= nums[i]){
                    st.pop();
                }
                res[i] = st.empty() ? -1 : st.top();
                st.push(nums[i]);
            }
            return res;
        }

};                   
                   
int main() {
    int n = 6;
    vector<int> arr = {5, 7, 1, 4, 6, 17};
    Solution sol; 
    vector<int> ans = sol.nextGreaterElements(arr);
    cout << "The next greater elements are: ";
    for(int i=0; i < n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}