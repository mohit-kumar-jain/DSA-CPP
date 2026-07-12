#include <bits/stdc++.h>
using namespace std;

// T.C -> O(2^n), S.C -> O(N).
const long long MOD = 1e9 + 7;
long long power(long long x, long long n) {
    long long ans = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            ans = (ans * x) % MOD;
        }
        x = (x * x) % MOD;
        n = n / 2;
    }
    return ans;
}
int countGoodNumbers(long long n) {
    long long even = (n + 1) / 2;
    long long odd = n / 2;
    return (power(5, even) * power(4, odd)) % MOD;
}


int main() {
    int n = 1;
    cout << countGoodNumbers(1) << endl;
    return 0;
}
