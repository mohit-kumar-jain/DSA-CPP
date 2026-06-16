#include<bits/stdc++.h>
using namespace std;

// Brute. T.C -> O(n*n) ,S.C -> O(1).
// int reversePairs(vector<int>& nums){
//     int n = nums.size();
//     int cnt = 0;
//     for (int  i = 0; i < n; i++)
//     {
//         for (int j = i+1; j < n; j++)
//         {
//             if(nums[i] > 2 * nums[j]){
//                 cnt++;
//             }   
//         }
//     }
//     return cnt;
// }

// Better. T.C -> O(nlogn) ,S.C -> O(1).
void merge(vector<int>& nums,int low,int mid,int high){
    int left =low, right = mid+1;
    vector<int> temp;
    while(left <= mid && right <= high){
        if(nums[left] <= nums[right]){
            temp.push_back(nums[left]);
            left++;
        }else{
            temp.push_back(nums[right]);
            right++;
        }
    }
    while(left <= mid){
        temp.push_back(nums[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(nums[right]);
        right++;
    }
    for(int i = low ; i <= high;i++){
        nums[i] = temp[i-low];
    }
}

int countPairs(vector<int> &arr, int low, int mid, int high) {
    int right = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++) 
    {
        while (right <= high && arr[i] > 2 * arr[right])
         right++;
        cnt += (right - (mid + 1));
    }
    return cnt;
}

int mergeSort(vector<int>& nums,int low,int high){
    int mid = (low+high)/2;
    int cnt = 0;
    if(low >= high){
        return cnt;
    }
    cnt += mergeSort(nums,low,mid);
    cnt += mergeSort(nums,mid+1,high);
    cnt += countPairs(nums,low,mid,high);
    merge(nums,low,mid,high);
    return cnt;
}

int reversePairs(vector<int>& nums){
    int n = nums.size();
    return mergeSort(nums,0,n-1);
}

int main(){
    vector<int> arr = {7,5,1,2,6};
    int n = arr.size();
    cout << reversePairs(arr);
    return 0;
}