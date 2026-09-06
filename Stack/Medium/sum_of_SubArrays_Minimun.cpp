#include<bits/stdc++.h>
using namespace std;
               
// Brute. T.C -> O(N*N), S.c -> O(N).
// int sumSubArray(vector<int>& nums) {
//     int total = 0;
//     int mod = 1e9+7;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         int minimum = nums[i];
//         for (int j = i; j < nums.size(); j++)
//         {
//             minimum = min(minimum,nums[j]);
//             total = (total + minimum) % mod;
//         }
//     }
//     return total;
// }                   
                   
// Optimal. T.C -> O(N), S.c -> O(N).
vector<int> pse(vector<int>& nums) {
    vector<int> ans(nums.size());
    stack<int> st;
    for (int i = 0; i < nums.size(); i++)
    {
        while (!st.empty() && nums[st.top()] > nums[i])
        {
            st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return ans;
}

vector<int> nse(vector<int>& nums) {
    vector<int> ans(nums.size());
    stack<int> st;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && nums[st.top()] > nums[i])
        {
            st.pop();
        }
        ans[i] = st.empty() ? nums.size() : st.top();
        st.push(i);
    }
    return ans;
}

int sumSubArray(vector<int>& nums) {
    int total = 0;
    vector<int> Nse = nse(nums);
    vector<int> Pse = pse(nums);
    int mod = (int) 1e9+7;
    stack<int> st;
    for (int i = 0; i < nums.size(); i++)
    {
        int left =  i - Pse[i];
        int right = Nse[i] - i;
        total = (total + (left * right * 1LL * nums[i])% mod) % mod;
    }
    return total;
}                   
                   

int main() {
    vector<int> arr = {2,3,1};
    cout << sumSubArray(arr) << endl;
    return 0;
}