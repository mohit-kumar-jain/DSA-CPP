#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> &nums)
{
    int ones = 0;
    int twos = 0;
    for (const int num : nums)
    {
        ones ^= (num & ~twos);
        twos ^= (num & ~ones);
    }
    return ones;
}

int main()
{
    vector<int> num = {1, 0, 1, 0, 2};
    cout << singleNumber(num) << endl;
    return 0;
}