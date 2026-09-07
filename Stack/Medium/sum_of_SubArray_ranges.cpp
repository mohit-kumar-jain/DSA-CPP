#include<bits/stdc++.h>
using namespace std;
                   
// Brute. T.C -> O(N*N) , S.C -> O(n).
// int sumRanges (vector<int>& nums) {
//     int n = nums.size();
//     vector<int> res(n);
//     int total = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int largest = nums[i], smallest = nums[i];
//         for (int j = i+1; j < n; j++)
//         {
//             largest = max(largest,nums[j]);
//             smallest = min(smallest,nums[j]);
//             total += (largest - smallest);
//         }
//     }
//     return total;
// }          
                   
// Optimal. T.C -> O(N) , S.C -> O(n).
vector<int> nse(vector<int>& nums) {
    vector<int> res(nums.size());
    stack<int> st;
    for (int i = nums.size()-1; i >= 0; i--)
    {
        while(!st.empty() && nums[st.top()] >= nums[i]){
            st.pop();
        }
        res[i] = st.empty() ? nums.size() : st.top();
        st.push(i);
    }
    
    return res;
}

vector<int> pse(vector<int>& nums) {
    vector<int> res(nums.size());
    stack<int> st;
    for (int i = 0; i < nums.size(); i++)
    {
        while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }
        res[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return res;
}

long long sumSubMin(vector<int>& nums) {
    long long total = 0;
    int n = nums.size();
    int mod = (int) 1e9+7;
    vector<int> NSE = nse(nums);
    vector<int> PSE = pse(nums);
    for (int i = 0; i < n; i++)
    {
        long long left = i - PSE[i];
        long long right = NSE[i] - i;
        total = (total + (left * right * 1LL * nums[i]) % mod) % mod;
    }
    return total;
}

vector<int> nge(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n);
    stack<int> st;

    for(int i = n - 1; i >= 0; i--) {

        while(!st.empty() && nums[st.top()] <= nums[i]) {
            st.pop();
        }

        res[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    return res;
}

vector<int> pge(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n);
    stack<int> st;

    for(int i = 0; i < n; i++) {

        while(!st.empty() && nums[st.top()] < nums[i]) {
            st.pop();
        }

        res[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    return res;
}

long long sumSubMax(vector<int>& nums) {
    long long total = 0;
    int n = nums.size();
    int mod = 1e9 + 7;

    vector<int> NGE = nge(nums);
    vector<int> PGE = pge(nums);

    for(int i = 0; i < n; i++) {

        long long left = i - PGE[i];
        long long right = NGE[i] - i;

        total = (total + (left * right % mod) * nums[i]) % mod;
    }

    return total;
}

int sumRanges (vector<int>& nums) {
    return sumSubMax(nums)  - sumSubMin(nums);
}          
                   
int main() {
    vector<int> nums = {1,4,3,2};
    cout << sumRanges(nums) << endl;
    return 0;
}