#include <bits/stdc++.h>
using namespace std;

vector<int> targetIndices(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    vector<int> res;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target)
        {
            res.push_back(i);
        }
        else if (nums[i] > target)
        {
            break;
        }
    }
    return res;
}

int main()
{
    vector<int> nums = {7,6,0,5,1,2,1,3};
    int target = 1;
    vector<int> res = targetIndices(nums, target);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}