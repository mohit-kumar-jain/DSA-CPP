#include <bits/stdc++.h>
using namespace std;

// Brute. T.C -> O((max(arr[])-min(arr[])+1) * N), S.C -> O(1).

// bool divideArr(vector<int>& a,int number,int l){
//     int n = a.size();
//     int res = 0;
//     for(int i = 0;i < n;i++){
//         res += ceil((double) a[i] / (double)number); 
//     }
//     return (res <= l);
// }

// int smallDivisor(vector<int>& a,int l){
//     int n = a.size();
//     for (int i = 1; i <= n; i++)
//     {
//         if(divideArr(a,i,l)){
//             return i;
//         }
//     }
//     return -1;
// }

// Optimal. T.C -> O(log(max(arr[])-min(arr[])+1) * N), , S.C -> O(1).
bool divideArr(vector<int>& a,int number,int l){
    int n = a.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += (a[i] + number - 1)/number;
    }  // a[i] + number - 1 / number
    return cnt <= l;
}

int smallDivisor(vector<int>& a,int l){
    int n = a.size();
    int low = 1;
    int high = *max_element(a.begin(),a.end());
    int res = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if(divideArr(a,mid,l)){
            res = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return res;
}

int main()
{
    vector<int> arr = {21212,10101,12121};
    int limit = 1000000;
    cout << smallDivisor(arr, limit);
    return 0;
}