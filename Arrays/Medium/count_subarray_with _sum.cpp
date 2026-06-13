#include <bits/stdc++.h>
using namespace std;

// Brute - Force. T.C -> O(n*n) , S.C -> 0(1)
// int countSubArray(vector<int>& arr,int k){
//     int count = 0;
//     int n = arr.size();
//     for (int i = 0; i < n; i++)
//     {
//         int sum = 0;
//         for (int j = i; j < n; j++)
//         {
//             sum += arr[j];
//             if(sum == k){
//                 count += 1;
//             }
//         } 
//     }
//     return count;
// }

// Better. T.C -> O(n) , S.C -> 0(n)
int countSubArray(vector<int>& arr,int k){
    int n = arr.size();
    int prefixsum = 0;
    int count = 0;
    unordered_map<int,int> mpp;
    for (int i = 0; i < n; i++)
    {
        prefixsum += arr[i];
        int remaining = prefixsum - k;
        count += mpp[remaining];
        mpp[prefixsum] += 1;
    }
    return count;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0;i < n;i++)
        cin >> arr[i];
    int k;
    cin >> k;
    cout<<countSubArray(arr,k)<<endl;
}