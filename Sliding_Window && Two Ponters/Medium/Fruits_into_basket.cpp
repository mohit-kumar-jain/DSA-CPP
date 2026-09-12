#include <bits/stdc++.h>
using namespace std;

// Brute. T.C -> O(N*N), S.C -> O(1).
// int totalFruit(vector<int>& fruits)
// {
//     int maxFruits = 0;
//     for (int start = 0; start < fruits.size(); ++start)
//     {
//         unordered_map<int, int> basket;
//         int currentCount = 0;
//         for (int end = start; end < fruits.size(); ++end)
//         {
//             basket[fruits[end]]++;
//             if (basket.size() > 2)
//             {
//                 break;
//             }
//             currentCount++;
//         }
//         maxFruits = max(maxFruits, currentCount);
//     }
//     return maxFruits;
// }

// Better. T.C -> O(N), S.C -> O(1).
// int totalFruit(vector<int> &fruits)
// {
//     unordered_map<int, int> basket;
//     int maxFruits = 0;
//     int left = 0;
//     for (int right = 0; right < fruits.size(); right++)
//     {
//         basket[fruits[right]]++;
//         while (basket.size() > 2)
//         {
//             basket[fruits[left]]--;
//             if (basket[fruits[left]] == 0)
//             {
//                 basket.erase(fruits[left]);
//             }
//             left++;
//         }
//         maxFruits = max(maxFruits, right - left + 1);
//     }
//     return maxFruits;
// }

// Optimal. T.C -> O(N), S.C -> O(1).
int totalFruit(vector<int> &fruits)
{
    int maxlen = 0;
    int lastfruit = -1, secondlastfruit = -1;
    int currcount = 0, lastfruitstreak = 0;
    for (int fruit : fruits)
    {
        if (fruit == lastfruit || fruit == secondlastfruit)
        {
            currcount++;
        }
        else
        {
            currcount = lastfruitstreak + 1;
        }
        if (fruit == lastfruit)
        {
            lastfruitstreak++;
        }
        else
        {
            lastfruitstreak = 1;
            secondlastfruit = lastfruit;
            lastfruit = fruit;
        }
        maxlen = max(maxlen, currcount);
    }
    return maxlen;
}

int main()
{
    vector<int> fruits = {1, 2, 3, 2, 2};
    cout << totalFruit(fruits) << endl;
    return 0;
}
