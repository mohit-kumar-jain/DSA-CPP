#include<bits/stdc++.h>
using namespace std;

// Brute. T.C -> O(n*n) ,S.C -> O(1).
// int countInversion(vector<int> nums){
//     int cnt = 0;
//     int n = nums.size();
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if(nums[i] > nums[j]){
//                 cnt++;
//             }
//         }
//     }
//     return cnt;
// }

// Optimal. T.C -> O(nlogn) ,S.C -> O(1).
int merge(vector<int>& nums, int low, int mid, int high) {
    int cnt = 0;
    int left = low;
    int right = mid + 1;
    vector<int> temp;
    while (left <= mid && right <= high) {
        if (nums[left] <= nums[right]) {
            temp.push_back(nums[left]);
            left++;
        }
        else {
            temp.push_back(nums[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }
    while (left <= mid) {
        temp.push_back(nums[left]);
        left++;
    }
    while (right <= high) {
        temp.push_back(nums[right]);
        right++;
    }
    for (int i = low; i <= high; i++) {
        nums[i] = temp[i - low];
    }
    return cnt;
}

int mergeSort(vector<int>& nums, int low, int high) {
    if (low >= high)
        return 0;
    int mid = (low + high) / 2;
    int cnt = 0;
    cnt += mergeSort(nums, low, mid);
    cnt += mergeSort(nums, mid + 1, high);
    cnt += merge(nums, low, mid, high);
    return cnt;
}

int countInversion(vector<int>& nums) {
    return mergeSort(nums, 0, nums.size() - 1);
}

int main(){
    vector<int> arr = {5,3,2,4,1};
    cout << countInversion(arr);
    return 0;
}