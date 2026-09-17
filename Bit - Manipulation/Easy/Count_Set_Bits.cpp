#include<bits/stdc++.h>
using namespace std;
      
// Brute. T.C -> O(log n), S.C -> O(1).
// int countSet(int n) {
//     int cnt = 0;
//     while(n > 0) {
//         cnt += (n & 1);
//         n >>= 1;
//     }
//     return cnt;
// }   

// Optimal. T.C -> O(Number of set bits), S.C -> O(1).
int countSet(int n) {
    int cnt = 0;
    while(n > 0) {
        n = n & (n - 1);
        cnt++;
    }
    return cnt;
}                 
                   
int main() {
    int n = 65;
    cout << n << " has " << countSet(n) << " set bits." << endl;
    return 0;
}