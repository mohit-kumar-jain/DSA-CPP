#include <bits/stdc++.h>
using namespace std;

int floorArray(vector<int> &nums, int target)
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
        else if (nums[mid] < target)
        {
            ans = nums[mid];
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 3, 5, 7, 9, 15, 69};
    int target;
    cin >> target;
    cout << floorArray(arr, target) << endl;
    return 0;
}