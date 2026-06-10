#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Optimal . T.C -> O(n) ,S.C -> O(n).
void rearrangeElements(int nums[], int n)
{
    int pos[n], neg[n];
    int p = 0, q = 0;
    for(int i = 0; i < n; i++)
    {
        if(nums[i] >= 0)
            pos[p++] = nums[i];
        else
            neg[q++] = nums[i];
    }
    int index = 0;
    int i = 0, j = 0;
    while(i < p && j < q)
    {
        nums[index++] = pos[i++];
        nums[index++] = neg[j++];
    }
    while(i < p)
    {
        nums[index++] = pos[i++];
    }
    while(j < q)
    {
        nums[index++] = neg[j++];
    }
    printArray(nums, n);
}

int main()
{
    int n;
    cin >> n;

    int nums[n];

    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    rearrangeElements(nums, n);

    return 0;
}