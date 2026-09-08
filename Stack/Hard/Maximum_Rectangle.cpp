#include<bits/stdc++.h>
using namespace std;
                   
int largestHistogram(vector<int>& nums) {
    int n = nums.size();
    stack<int> st;
    int maxi = 0;
    for (int i = 0; i <= n; i++)
    {
        while(!st.empty() && (i == n || nums[st.top()] >= nums[i])){
            int height = nums[st.top()];
            st.pop();
            int width;
            if(st.empty()) width = i;
            else width = i - st.top() - 1;
            maxi = max(maxi, (height * width));
        }
        if(i < n){
            st.push(i);
        }
    }
    return maxi;
}

int maximumRectangle(vector<vector<int>>& mat) {
    if(mat.empty()) return 0;
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> preSum(n, vector<int>(m));
    for (int j = 0; j < m; j++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += mat[i][j];
            if(mat[i][j] == 0) sum = 0;
            preSum[i][j] = sum;
        }
    }
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi , largestHistogram(preSum[i]));
    }
    
    return maxi;
}                   
                   
int main() {
    vector<vector<int>> mat = {{1,0,1,0,0},{1,0,1,1,1},{1,1,1,1,1},{1,0,0,1,0}};
    cout << maximumRectangle(mat) << endl;
    return 0;
}