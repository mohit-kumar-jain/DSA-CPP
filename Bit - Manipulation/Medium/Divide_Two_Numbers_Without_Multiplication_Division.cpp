#include<bits/stdc++.h>
using namespace std;
                  
// T.C -> O(log n) ^ 2, S.C -> O(1).
int divideNumbers(int n, int d) {
    if(n == d) return 1;
    bool sign = true;
    if(n < 0 && d > 0) sign = false;
    if(n >= 0 && d < 0) sign = false;
    n = abs(n);
    d = abs(d);
    int ans = 0;
    while(n >= d) {
        int cnt = 0;
        while(n >= (d << (cnt + 1))){
            cnt++;
        }
        ans += (1 << cnt);
        n -= (d << cnt);
    }
    return sign ? ans : -ans;
}                   
                   
int main() {
    int dividend = -22, divisor = 7;
    cout << divideNumbers(dividend, divisor) << endl;
    return 0;
}