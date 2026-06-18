#include <bits/stdc++.h>
using namespace std;

// Brute. T.C -> O((max(arr[])-min(arr[])+1) * N), S.C -> O(1).

// bool bloomF(vector<int> &a, int day, int m, int k)
// {
//     int bouquets = 0, cnt = 0;
//     // for (int bloom : a)
//     for (int i = 0; i < a.size(); i++)
//     {
//         int bloom = a[i];
//         if (bloom <= day)
//         {
//             cnt++;
//             if (cnt == k)
//             {
//                 bouquets++;
//                 cnt = 0;
//             }
//         }
//         else
//         {
//             cnt = 0;
//         }
//     }
//     return bouquets >= m;
// }

// int roseGarden(vector<int> &a, int m, int k)
// {
//     int n = a.size();
//     long long totalFlowers = 1LL * m * k;
//     if (totalFlowers > n)
//         return -1;
//     int low = *min_element(a.begin(), a.end());
//     int high = *max_element(a.begin(), a.end());
//     for (int i = low; i <= high; i++)
//     {
//         if (bloomF(a, i, m, k))
//         {
//             return i;
//         }
//     }
//     return -1;
// }

// Optimal. T.C -> O(log(max(arr[])-min(arr[])+1) * N), , S.C -> O(1).
bool bloomF(vector<int> &a, int day, int m, int k)
{
    int bouquet = 0, cnt = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] <= day){
            cnt++;
            if(cnt == k){
                bouquet++;
                cnt = 0;
            }
        }else{
            cnt = 0;
        }
    }
    return bouquet >= m;
}

int roseGarden(vector<int> &a, int m, int k)
{
    if ((long long)m * k > a.size())
        return -1;
    int low = *min_element(a.begin(), a.end());
    int high = *max_element(a.begin(), a.end());
    int res = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (bloomF(a, mid, m, k))
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}

int main()
{
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int m = 2, k = 3;
    cout << roseGarden(arr, m, k);
    return 0;
}