#include <bits/stdc++.h>
using namespace std;

int smallestIndex(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int digitSum = 0;
        for (int j = nums[i]; j > 0; j /= 10)
            digitSum += j % 10;
        if (digitSum == i)
            return i;
    }
    return -1;
}

int main()
{
    vector<int> nums = {1, 3, 2, 6};
    cout << smallestIndex(nums) << endl;
    return 0;
}