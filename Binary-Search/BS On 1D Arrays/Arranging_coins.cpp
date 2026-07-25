#include <bits/stdc++.h>
using namespace std;

int arrangeCoins(int n)
{
    long left = 1;
    long right = n;
    while (left <= right)
    {
        long mid = left + (right - left) / 2;
        long coins = mid * (mid + 1) / 2;
        if (coins == n)
            return mid;
        else if (coins < n)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return right;
}

int main(){
    int n = 5;
    cout << arrangeCoins(n) << endl;
    return 0;
}