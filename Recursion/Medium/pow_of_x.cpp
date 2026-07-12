#include <iostream>
using namespace std;

// Brute. T.C -> O(N), S.C -> O(1).
// double myPow(double x,int n){
//     if(x == 0) return 0;
//     if(x == 1 || n == 0) return 1;
//     double res = 1.00;
//     long long temp = n;
//     if (n < 0) {
//         x = 1 / x;
//         temp = -1 * 1LL * n;
//     }
//     for (long long i = 0; i < temp; i++)
//     {
//         res = res * x;
//     }
//     return res;
// }

// Optimal. T.C -> O(logN), S.C -> O(logN).
double myPow(double x, int n)
{
    if (x == 0)
        return 0;
    if (x == 1 || n == 0)
        return 1;
    long long N = n;
    if (N < 0) {
        x = 1.0 / x;
        N = -N;
    }
    if (N % 2 == 0)
    {
        return myPow(x * x, N / 2);
    }
    return x * myPow(x * x, n / 2);
}

int main()
{
    int x, n;
    cin >> x >> n;
    int num = n;
    cout << myPow(x, num) << endl;
    return 0;
}