#include <bits/stdc++.h>
using namespace std;

// Brute. T.C -> O(n), S.C -> O(1).
// int finSingle(vector<int>& nums){
//     int n = nums.size();
//     int xorr = 0;
//     for (int i = 0; i < n; i++)
//     {
//         xorr ^= nums[i];    
//     }
//     return xorr;
// }

// Better. T.C -> O(logn), S.C -> O(1).
int finSingle(vector<int>& nums){
    int n = nums.size();
    int low = 1, high = n - 2;
    if (n == 1) return nums[0];
    if(nums[0] != nums[low]) return nums[0];
    if(nums[n-1] != nums[high]) return nums[n-1];
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(nums[mid] != nums[mid +1] && nums[mid] != nums[mid - 1]){
            return nums[mid];
        }
        if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) ||
            (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    } 
    return -1;
}

int main()
{
    vector<int> arr = {1,1,2,2,3,4,4,5,5,6,6,7,7};
    cout << finSingle(arr) << endl;
    return 0;
}