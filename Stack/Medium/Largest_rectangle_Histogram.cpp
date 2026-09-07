#include<bits/stdc++.h>
using namespace std;
       
// Brute. T.C -> O(N*N) , S.C -> O(1).

// int LargestRectangle(vector<int>& heights) {
//     int maxArea = 0; 
//     int n = heights.size();
//     for (int i = 0; i < n; i++) {
//         int minHeight = INT_MAX;
//         for (int j = i; j < n; j++) {
//             minHeight = min(minHeight, heights[j]);
//             int width = j - i + 1;
//             int area = minHeight * width;
//             maxArea = max(maxArea, area);
//         }
//     }
//     return maxArea;
// }
 

// Optimal 1. T.C -> O(5N) , S.C -> O(2N).

// vector<int> PSE(vector<int>& nums) {
//     stack<int> st;
//     int n = nums.size();
//     vector<int> res(n);
//     for (int i = 0; i < n; i++)
//     {
//         while(!st.empty() && nums[st.top()] >= nums[i]){
//             st.pop();
//         }
//         res[i] = st.empty() ? -1 : st.top();
//         st.push(i);
//     }
//     return res;
// }

// vector<int> NSE(vector<int>& nums) {
//     stack<int> st;
//     int n = nums.size();
//     vector<int> res(n);
//     for (int i = n -1; i >= 0; i--)
//     {
//         while(!st.empty() && nums[st.top()] >= nums[i]) {
//             st.pop();
//         }
//         res[i] = st.empty() ? n : st.top();
//         st.push(i);
//     }
//     return res;
// }

// int LargestRectangle(vector<int>& heights) {
//     int n = heights.size();
//     vector<int> pse = PSE(heights);
//     vector<int> nse = NSE(heights);
//     int maxi = 0;
//     for (int i = 0; i < n; i++)
//     {
//         maxi = max(maxi , (nse[i] - pse[i] - 1) * heights[i]);
//     }
//     return maxi;
// }
       

// Optimal 2. T.C -> O(N) , S.C -> O(N).
int LargestRectangle(vector<int>& heights) {
    int n = heights.size();
    stack<int> st;
    int maxi = 0;
    for (int i = 0; i <= n; i++)
    {
        while(!st.empty() && ( i == n || heights[st.top()] >= heights[i])) {
            int height = heights[st.top()];
            st.pop();
            int width;
            if(st.empty()) width = i;
            else width = i - st.top() - 1;
            maxi = max(maxi,(height * width));
        }
        st.push(i);
    }
    return maxi;
}

int main() {
    vector<int> heights = {2,1,5,6,2,3};
    cout << LargestRectangle(heights) << endl;
    return 0;
}