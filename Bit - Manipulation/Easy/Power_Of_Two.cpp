#include<bits/stdc++.h>
using namespace std;
       
// Brute. T.C -> O(log n) , S.C -> O(1).
// int powerOfTwo(int n) {
//     if(n < 0) return -1;
//     while(n % 2 == 0) 
//     {
//         n /= 2;
//     }
//     return n == 1;
// }                   

// Optimal. T.C -> O(1) , S.C -> O(1).
int powerOfTwo(int n) {
    return (n > 0) && (n & (n - 1)) == 0;
}                   
                   
int main() {
    int n = 62;
    if(powerOfTwo(n)) cout << n << " is a power of two." << endl;
    else cout << n << " is not a power of two." << endl;
    return 0;
}