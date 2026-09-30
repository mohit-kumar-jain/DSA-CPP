#include <bits/stdc++.h>
using namespace std;

// Optimal. T.C -> O(N), S.C -> O(1).
int canJump(vector<int>& nums)
{
    int n = nums.size();
    if (n <= 1)
    {
        return 0;
    }
    int jumps = 0;
    int l = 0, r = 0;
    while(r < n-1) {
        int farthest = 0;
        for (int i = l; i <= r; i++)
        {
            farthest = max(farthest, i + nums[i]);
        }
        jumps++;
        l = r + 1;
        r = farthest;
    }
    return jumps;
}

int main()
{
    vector<int> nums = {2, 2, 0, 1, 4};
    cout << canJump(nums) << endl;
    return 0;
}