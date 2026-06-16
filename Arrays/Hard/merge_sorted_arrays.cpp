#include<bits/stdc++.h>
using namespace std;

// Brute. T.C -> O(2(m+n)) ,S.C -> O(m+n).
// void mergeSorted(vector<int>& nums1,vector<int>& nums2){
//     int m = nums1.size();
//     int n = nums2.size();
//     vector<int> ans(m+n);
//     int left = 0, right = 0;
//     int index = 0;
//     while(left < m && right < n){
//         if(nums1[left] <= nums2[right]){
//             ans[index] = nums1[left];
//             left++;
//             index++;
//         }else{
//             ans[index] = nums2[right];
//             right++,index++;
//         }
//     }
//     while(left < m){
//         ans[index++] = nums1[left++];
//     }
//     while(right < n){
//         ans[index++] = nums2[right++];
//     }
//     for(int i = 0;i < m+n;i++){
//         if(i < n) nums1[i] = ans[i];
//         else nums2[i-n] = ans[i];
//     }
// }

// Optimal - 1. T.C -> O(min(m,n)) + O(mlogm) + O(nlogn) ,S.C -> O(1).
// void mergeSorted(vector<int>& nums1,vector<int>& nums2){
//     int m = nums1.size();
//     int n = nums2.size();
//     int left = m-1,right = 0;
//     while(left >= 0 && right < n){
//         if(nums1[left] > nums2[right]){
//             swap(nums1[left],nums2[right]);
//             left--,right++;
//         }else{
//             break;
//         }
//     }
//     sort(nums1.begin(),nums1.end());
//     sort(nums2.begin(),nums2.end());
// }

// Optimal - 2. T.C ->  O(log(n+m)*(m+n)) ,S.C -> O(1).
//  Shell Sort.

void mergeSorted(vector<int>& nums1, vector<int>& nums2)
{
    int m = nums1.size();
    int n = nums2.size();
    int len = m + n;
    int gap = (len / 2) + (len % 2);
    while(gap > 0)
    {
        int left = 0;
        int right = left + gap;
        while(right < len)
        {
            // nums1 and nums2
            if(left < m && right >= m)
            {
                if(nums1[left] > nums2[right - m])
                    swap(nums1[left], nums2[right - m]);
            }
            // nums2 and nums2
            else if(left >= m)
            {
                if(nums2[left - m] > nums2[right - m])
                    swap(nums2[left - m], nums2[right - m]);
            }
            // nums1 and nums1
            else
            {
                if(nums1[left] > nums1[right])
                    swap(nums1[left], nums1[right]);
            }
            left++;
            right++;
        }
        if(gap == 1)    break;
        gap = (gap / 2) + (gap % 2);
    }
}


int main(){
    vector<int> arr1 = {1,3,5,7,9};
    vector<int> arr2 = {0,2,6,7,8};
    mergeSorted(arr1,arr2);
    for(auto it : arr1){
        cout<<it<<" ";
    }
    cout<<endl;
    for(auto it : arr2){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}