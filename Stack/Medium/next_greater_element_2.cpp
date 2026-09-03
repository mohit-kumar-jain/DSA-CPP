#include <bits/stdc++.h>
using namespace std;

class Solution {
    stack<int> st;
    public:
    // Brute. T.C -> O(N*N), S.C -> O(N).

    // vector<int> nextGreaterElements(vector<int> arr) {
    //     int n = arr.size(); 
    //     vector<int> ans(n, -1);
    //     for(int i=0; i < n; i++) {
    //         int currEle = arr[i];
    //         for(int j=1; j < n; j++) {
    //             int ind = (j+i) % n;
    //             if(arr[ind] > currEle) {
    //                 ans[i] = arr[ind];
    //                 break;
    //             }    
    //         }
    //     }
    //     return ans;
    // }

    // Optimal. T.C - > O(4*N), S.C -> O(N)+O(N).
    vector<int> nextGreaterElements(vector<int> arr) {
        int n = arr.size();
        vector<int> res (n,-1);
        for (int i = 2*n-1; i >= 0; i--)
        {
            while(!st.empty() && st.top() <= arr[i % n]) {
                st.pop();
            }
            if(i < n) {
                res[i] = st.empty() ? -1 : st.top();
            }
            st.push(arr[i % n]);
        }
        return res;
    }
};

int main() {
    int n = 6;
    vector<int> arr = {5, 7, 1, 7, 6, 0};
    Solution sol; 
    vector<int> ans = sol.nextGreaterElements(arr);
    cout << "The next greater elements are: ";
    for(int i=0; i < n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}