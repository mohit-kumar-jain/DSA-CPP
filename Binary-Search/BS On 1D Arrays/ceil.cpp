#include <bits/stdc++.h>
using namespace std;

int ceilArray(vector<int> &nums, int target)
{
    int low = 0, n = nums.size(), high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            return nums[mid];
        }
        else if (nums[mid] > target)
        {
            ans = nums[mid];
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 3, 5, 7, 9, 15, 69};
    int target;
    cin >> target;
    cout << ceilArray(arr, target) << endl;
    return 0;
}