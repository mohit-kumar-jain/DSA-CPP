#include <bits/stdc++.h>
using namespace std;

// Brute. T.C -> O(sqrt(n)), S.C -> O(1).
// int nthRoot(int n, int m)
// {
//     if(n == 0 || m == 0)
//         return 0;
//     for (int i = 1; i <= m; i++)
//     {
//         long long power = pow(i, n);
//         if (power == m)
//             return i;
//         if (power > m)
//             break;
//     }
//     return -1;
// }

// Optimal. T.C -> O(logm), S.C -> O(1).
int nthRoot(int n, int m) {
    int low = 1, high = m;
    while (low <= high) {
        int mid = (low + high) / 2;
        long long ans = 1;
        for (int i = 0; i < n; i++) {
            ans *= mid;
            if (ans > m) break;
        }
        if (ans == m) return mid;
        if (ans < m) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << nthRoot(n,m);
    return 0;
}