#include<bits/stdc++.h>
using namespace std;
 
// Brute. T.C -> O(log N), S.C -> O(log N).
// bool checkIth(int n, int i) {
//     string binary = "";
//     while(n > 0) {
//         binary += ((n % 2 == 1)? '1' : '0');
//         n /= 2;
//     }
//     if(i >= binary.size()) return false;
//     return binary[i] == '1';
// }    

// 1. Optimal. T.C -> O(1), S.C -> O(1).
// bool checkIth(int n, int i) {
//     return (n & (1 << i));
// }

// 2. Optimal. T.C -> O(1), S.C -> O(1).
bool checkIth(int n, int i) {
    return (1 & (n >> i));
}
                   
int main() {
    int n = 13, i = 0;
    cout << checkIth(n,i) << endl;
    return 0;
}