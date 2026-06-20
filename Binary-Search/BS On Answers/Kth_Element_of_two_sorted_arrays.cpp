#include <bits/stdc++.h>
using namespace std;

// Brute. T.C -> O(n+m+k), S.C -> O(m+n).
// int findK(vector<int> &a, vector<int> &b, int k){
//     vector<int> c;
//     int i = 0, j = 0;
//     int n = a.size(), m = b.size();
//     int maxii = m + n;
//     while(i < n && j < m){
//         if(a[i] < b[j]){
//             c.push_back(a[i++]);
//         }else{
//             c.push_back(b[j++]);
//         }
//     }
//     while(i < n){
//         c.push_back(a[i++]);
//     }
//     while(j < m){
//         c.push_back(b[j++]);
//     }
//     for (int i = 0; i < maxii; i++)
//     {
//         if(i+1 < k){
//             continue;
//         }
//         if(i+1 == k){
//             return c[i];
//         }
//     }
//     return -1;
// }

// Optimal. T.C -> O(log(min(m,n))), S.C -> O(1).
int findK(vector<int> &a, vector<int> &b, int k){
    int n = a.size(), m = b.size();
    int maxii = n + m;
    if(n > m) return findK(b,a,k);
    int left = k;
    int low = max(0,k-m), high = max(k,n);
    while(low <= high){
        int mid1 = low + (high - low) / 2;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
        if(mid1 - 1 >= 0) l1 = a[mid1 - 1];
        if(mid2 - 1 >= 0) l2 = b[mid2 - 1];
        if(mid1 < n) r1 = a[mid1];
        if(mid2 < m) r2 = b[mid2];
        if(l1 <= r2 && l2 <= r1){
            return max(l1,l2);
        }else if(l1 > r2){
            high = mid1 - 1;
        }else{
            low = mid1 + 1;
        }
    }
}

int main()
{
    vector<int> arr1 = {1, 3};
    vector<int> arr2 = {2, 4, 6, 8};
    int k = 6;
    cout << findK(arr1, arr2,k);
    return 0;
}