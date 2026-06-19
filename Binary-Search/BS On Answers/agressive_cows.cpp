#include <bits/stdc++.h>
using namespace std;

// Brute. T.C -> O(nlogn)+ O((max-min) * n), S.C -> O(1).

// bool isPossible(vector<int>& stalls,int distance, int cows){
//     int cow = 1, last = stalls[0];
//     for (int i = 1; i < stalls.size(); i++)
//     {
//         if(stalls[i] - last >= distance){
//             cow++;
//             last = stalls[i];
//         }
//          if (cow >= cows) return true;
//     }
//     return  false;
// }

// int minimumDistance(vector<int>& stalls, int cows){
//     sort(stalls.begin(),stalls.end());
//     int  minimum = *min_element(stalls.begin(),stalls.end());
//     int  maximum = *max_element(stalls.begin(),stalls.end());
//     for (int i = 1; i < maximum - minimum; i++)
//     {
//         if(isPossible(stalls,i,cows)){
//             continue;
//         }else{
//             return (i - 1);
//         }
//     }
//     return -1;
// }

// Better. T.C -> O(nlogn) + O(log(max-min) * n), S.C -> O(1).

bool isPossible(vector<int>& stalls,int distance, int cows){
    int cow = 1, last = stalls[0];
    for (int i = 1; i < stalls.size(); i++)
    {
        if(stalls[i] - last >= distance){
            cow++;
            last = stalls[i];
        }
    }
    return cow >= cows ;
}

int minimumDistance(vector<int>& stalls, int cows){
    sort(stalls.begin(),stalls.end());
    int  low = 1 , n = stalls.size();
    int  high = stalls[n-1] - stalls[0];
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(isPossible(stalls,mid,cows)){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return high;
}

int main()
{
    vector<int> arr = {0,3,4,7,10,9};
    int cows = 4;
    cout << minimumDistance(arr, cows);
    return 0;
}