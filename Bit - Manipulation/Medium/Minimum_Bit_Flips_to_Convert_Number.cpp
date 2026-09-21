#include <bits/stdc++.h>
using namespace std;

// T.C -> O(log(start ^ goal)), S.C -> O(1).
int minBitFlips(int start, int goal)
{
    int xorResult = start ^ goal;
    int ans = 0;
    while (xorResult > 0)
    {
        ans += xorResult & 1;
        xorResult >>= 1;
    }
    return ans;
}

int main()
{
    int start = 10, goal = 5;
    cout << minBitFlips(start, goal) << endl;
    return 0;
}