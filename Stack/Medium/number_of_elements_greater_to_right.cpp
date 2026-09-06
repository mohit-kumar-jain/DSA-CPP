#include<bits/stdc++.h>
using namespace std;
      
// Brute. T.C -> O(N*N) , S.C -> O(N).
// vector<int> RightLargerElement(vector<int>& nums) {
//     vector<int> res(nums.size(),-1);
//     for (int i = 0; i < nums.size(); i++)
//     {
//         int count = 0;
//         for (int j = i+1; j < nums.size(); j++)
//         {
//             if(nums[j] > nums[i]) {
//                 count++;
//                 res[i] = count;
//             }
//         }   
//     }
//     return res;
// }                   
      
// Optimal. T.C -> O(n) , S.C -> O(n)
vector<int> RightLargerElement(vector<int> arr) {
    int n = arr.size(); 
    vector<int> ans(n);
    stack<int> st;
    for(int i = n-1; i >= 0; i--) {
        int currEle = arr[i];
        while(!st.empty() && st.top() <= currEle) {
            st.pop();
        }
        if(st.empty()) 
            ans[i] = -1;
        else 
            ans[i] = st.size();
        st.push(currEle);
    }
    return ans;
}

int main() {
    vector<int> arr = {6,8,0,1,3};
    vector<int> res = RightLargerElement(arr);
    for(int it : res) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}