#include<bits/stdc++.h>
using namespace std;

// Brute. T.C -> O(r-l+1), S.C -> O(1).
// int xorRange(int l, int r) {
//     if(l > r) return 0;
//     int ans = 0;
//     for (int i = l; i <= r; i++)
//     {
//         ans ^= i;
//     }
    
//     return ans;
// }    

int xorNum(int n) {
    int ans = 0;
    if(n % 4 == 1) {
        return 1;
    }else if(n % 4 == 2) {
        return n + 1;
    } else if(n % 4 == 3) {
        return 0;
    }else{
        return n;
    }
    return ans;
}
// Optimal. T.C -> O(1), S.C -> O(1).
int xorRange(int l, int r) {
    if(l > r) return 0;
    return xorNum(l-1) ^ xorNum(r);
}                   
               
                   
int main() {
    int l = 4, r = 8;
    cout << xorRange(l,r) << endl;
    return 0;
}