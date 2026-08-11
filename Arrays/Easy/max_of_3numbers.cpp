#include<bits/stdc++.h>
using namespace std;
                   
int maxProduct(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int res1 = nums[0] * nums[1] * nums[2];                 
    int res2 = nums[n-1] * nums[n-2] * nums[n - 3];   
    return max(res1, res2);              
}
int main() {
    int t;
    cout << "Enter the number of test cases : ";
    cin >> t;
    while(t--) {
        int inp;
        cout << " Enter the number of inputs in array : ";
        cin >> inp;
        vector<int> nums(inp,0);
        for (int  i = 0; i < inp; i++)
        {
            cin >> nums[i];
        }
        cout << maxProduct(nums) << endl;
    }
    return 0;
}