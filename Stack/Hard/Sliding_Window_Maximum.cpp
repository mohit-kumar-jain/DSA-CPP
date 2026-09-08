#include<bits/stdc++.h>
using namespace std;
       
// Brute. T.C -> O(k* (N - k)), S.C -> O(N).
vector<int>   maxWindow(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> res;
    for(int i = 0; i <= n - k; i++) {
        int maxi = arr[i];
        for (int  j = i; j < i + k; j++)
        {
            maxi = max(maxi, arr[j]);
        }
        res.push_back(maxi);
    }
    return res;
}

// Optimal. T.C -> O(2N), S.C -> O(N - k).
// vector<int>   maxWindow(vector<int>& arr, int k) {
//     int n = arr.size();
//     vector<int> res;
//     deque<int> dq;
//     for(int i = 0; i < n; i++){
//         if(!dq.empty() && dq.front() <= i - k){
//             dq.pop_front();
//         } 
//         while(!dq.empty() && arr[dq.back()] <= arr[i]){
//             dq.pop_back();
//         }
//         dq.push_back(i);
//         if(i >= k - 1) res.push_back(arr[dq.front()]);
//     }
//     return res;
// }                   
                   
int main() {
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> res = maxWindow(arr,k);
    for(int it : res) cout << it << " ";
    cout << endl;
    return 0;
}