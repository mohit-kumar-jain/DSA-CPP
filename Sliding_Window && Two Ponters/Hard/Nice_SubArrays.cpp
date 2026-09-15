#include<bits/stdc++.h>
using namespace std;
                   
// Brute. T.C -> O(N*N) , S.C -> O(1).
// int niceSubArray(vector<int>& arr, int k) {
//     int n = arr.size(), count  = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int oddCnt = 0;
//         for (int j = i; j < n; j++)
//         {
//             if(arr[j] % 2 == 1) oddCnt++;
//             if(oddCnt > k) break;
//             else if(oddCnt == k) count++;
//         }
//     }
//     return count;
// } 

// Better. T.C -> O(N), S.C -> O(N).
// int niceSubArray(vector<int>& arr, int k) {
//     int res  = 0,oddCnt = 0;
//     unordered_map<int,int> freq;
//     freq[0] = 1;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         if(arr[i] % 2 == 1) oddCnt++;
//         if(freq.count(oddCnt - k)) res+= freq[oddCnt - k];
//         freq[oddCnt]++;
//     }
//     return res;
// }              

// Optimal. T.C -> O(N), S.C -> O(1).
int FindSubArray(vector<int>& arr, int k) {
    if(k < 0) return 0;
    int l = 0, sum = 0,cnt = 0;
    for (int r = 0; r < arr.size(); r++)
    {
        sum += (arr[r] % 2);
        while(sum > k){
            sum -= (arr[l] % 2);
            l++;
        }
        cnt += (r - l + 1);
    }
    return cnt;
}

int niceSubArray(vector<int>& arr, int k) {
    return FindSubArray(arr, k) - FindSubArray(arr, k- 1);
}

int main() {
    vector<int> nums = {1,1,2,1,1};
    int k = 3;
    cout << niceSubArray(nums, k) << endl;
    return 0;
}