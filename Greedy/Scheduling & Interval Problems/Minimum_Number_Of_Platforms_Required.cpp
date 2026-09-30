#include<bits/stdc++.h>
using namespace std;

// Brute. T.C -> O(N*N), S.C -> O(1).
// int minimumPlatform(vector<int>& arr, vector<int>& dep) {
//     int maxCnt = 0;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         int cnt = 0;
//         for (int j = 0; j < arr.size(); j++)
//         {
//             if(arr[j] <= arr[i] && dep[j] >= arr[i] ){
//                 cnt++;
//             }
//         }
//         maxCnt = max(cnt, maxCnt);
//     }
//     return maxCnt;
// }
                
// Optimal. T.C -> 2 * O(Nlog N + N), S.C -> O(1).
int minimumPlatform(vector<int>& arr, vector<int>& dep) {
    int cnt  = 0, maxCnt = 0;
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    int i = 0, j = 0;
    while(i < arr.size()) {
        if(arr[i] <= dep[j]){
            cnt++;
            i++;
        }else{
            cnt--;
            j++;
        }
        maxCnt = max(maxCnt, cnt);
    }
    return maxCnt;
}                   
                   
int main() {
    vector<int> Arrival = {900, 940, 950, 1100, 1500, 1800} ;
    vector<int>  Departure = {910, 1200, 1120, 1130, 1900, 2000};
    cout << minimumPlatform(Arrival, Departure) << endl; 
    return 0;
}