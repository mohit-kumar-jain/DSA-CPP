#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> mp;
    stack<int> st;

    for (int i = nums2.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums2[i])
            st.pop();

        mp[nums2[i]] = st.empty() ? -1 : st.top();
        st.push(nums2[i]);
    }

    vector<int> ans;
    for (int x : nums1)
        ans.push_back(mp[x]);

    return ans;
}
int main() {
    vector<int> nums1 = {2,4};
    vector<int> nums2 = {1, 2, 3, 4};
    vector<int> ans = nextGreaterElement(nums1,nums2);
    for(auto it : ans){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}