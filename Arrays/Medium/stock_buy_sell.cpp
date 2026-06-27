#include <bits/stdc++.h>
using namespace std;
// Brute. T.C -> O(n*n), S.C -> O(1).
int stockbuySell(vector<int> &prices)
{
    int maxProfit = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        for (int j = i + 1; j < prices.size(); j++)
        {
            int profit = prices[j] - prices[i];
            maxProfit = max(maxProfit, profit);
        }
    }
    return maxProfit;
}

// Optimal. T.C -> O(n), S.C -> O(1).
int stockbuySell(int arr[], int n)
{
    int maxi = 0, mini = arr[0];
    for (int i = 1; i < n; i++)
    {
        int profit = arr[i] - mini;
        maxi = max(maxi, profit);
        mini = min(mini, arr[i]);
    }
    return maxi;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << stockbuySell(arr, n);
    return 0;
}