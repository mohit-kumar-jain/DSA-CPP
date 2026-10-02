#include <bits/stdc++.h>
using namespace std;

// T.C -> O(N), S.C -> O(N).
int candy(vector<int> &ratings)
{
    int n = ratings.size();
    vector<int> candies(n, 1);

    for (int i = 1; i < n; i++)
    {
        if (ratings[i] > ratings[i - 1])
        {
            candies[i] = candies[i - 1] + 1;
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
        {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }
    int totalCandies = 0;
    for (int candyCount : candies)
    {
        totalCandies += candyCount;
    }
    return totalCandies;
}

int main()
{
    vector<int> ratings = {1, 2, 2};
    cout << candy(ratings) << endl;
    return 0;
}