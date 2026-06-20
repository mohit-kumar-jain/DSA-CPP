#include <bits/stdc++.h>
using namespace std;

// Brute. T.C -> O(n+m), S.C -> O(m+n).
// double medianArrays(vector<int>& nums1, vector<int>& nums2){
//     int n = nums1.size(), m = nums2.size();
//     vector<int> nums3;
//     int i = 0, j = 0;
//     while(i < n && j < m){
//         if(nums1[i] < nums2[j]){
//             nums3.push_back(nums1[i++]);
//         }else{
//             nums3.push_back(nums2[j++]);
//         }
//     }
//     while(i < n){
//         nums3.push_back(nums1[i++]);
//     }
//     while(j < m){
//         nums3.push_back(nums2[j++]);
//     }
//     int k = n + m;
//     if(k % 2 == 1){
//         return nums3[k/2] ;
//     }else{
//         return (double) ((double)nums3[(k/2)] + (double)nums3[(k / 2) - 1]) / 2.0;
//     }
// }

// Better. T.C -> O(n+m)), S.C -> O(1).
// double medianArrays(vector<int>& nums1, vector<int>& nums2){
//     int n = nums1.size(), m = nums2.size();
//     int ele1 = -1,ele2 = -1;
//     int cnt = 0;
//     int ind2 = ((m+n)/2);
//     int ind1 = ind2 - 1;
//     int i = 0,j = 0;
//     while (i < n && j < m)
//     {
//         if(ele1 != -1 && ele2 != -1) break;
//         if(nums1[i] < nums2[j]){
//             if (cnt == ind1) ele1 = nums1[i];
//             if (cnt == ind2) ele2 = nums1[i];
//             cnt++;
//             i++;
//         }else{
//             if (cnt == ind1) ele1 = nums2[j];
//             if (cnt == ind2) ele2 = nums2[j];
//             cnt++;
//             j++;
//         }
//     }
//     while(i < n){
//         if(ele1 != -1 && ele2 != -1) break;
//         if(cnt == ind1) ele1 = nums1[i];
//         if(cnt == ind2) ele2 = nums1[i];
//         cnt++,i++;
//     }
//     while(j < m){
//         if(ele1 != -1 && ele2 != -1) break;
//         if(cnt == ind1) ele1 = nums2[j];
//         if(cnt == ind2) ele2 = nums2[j];
//         cnt++,j++;
//     }
//     if((m+n)%2 == 1) return ele2;
//     else{
//         return (double) ((ele1 + ele2) / 2.0);
//     }
// }

// Optimal. T.C -> O(log(min(n,m))) , S.C -> O(1).
double medianArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size(), m = nums2.size();
    if (nums1 > nums2)
        return medianArrays(nums2, nums1);
    int maxx = (n + m);
    int left = (maxx + 1) / 2;
    int low = 0,high = n;
    while(low <= high){
        int mid1 = low + (high - low) / 2;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
        if(mid1 < n) r1 = nums1[mid1];
        if(mid2 < m) r2 = nums2[mid2];
        if(mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
        if(mid2 - 1 >= 0) l2 = nums2[mid2 - 1];
        if(l1 <= r2 && l2 <= r1){
            if(maxx % 2 == 1) return max(l1,l2);
            else return (double)(max(l1,l2) + min(r1,r2)) / 2.0;
        }
        else if(l1 > r2){
            high = mid1 - 1;
        }else{
            low  = mid1 + 1;
        }
    }
    return 0;
}

int main()
{
    vector<int> arr1 = {1, 3};
    vector<int> arr2 = {2, 4, 6, 8};
    cout << medianArrays(arr1, arr2);
    return 0;
}