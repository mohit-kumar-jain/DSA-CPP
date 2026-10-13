#include <bits/stdc++.h>
using namespace std;

long long maxAlternatingSum(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] = nums[i] * nums[i];
    }
    sort(nums.begin(), nums.end());
    long long a = 0, b = 0;

    int i = 0, j = n - 1;

    while (i < j)
    {
        a += nums[i];
        b += nums[j];
        i++;
        j--;
    }
    if (n % 2 == 1)
    {
        b += nums[j];
    }
    return b - a;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    cout << maxAlternatingSum(nums) << endl;
    return 0;
}