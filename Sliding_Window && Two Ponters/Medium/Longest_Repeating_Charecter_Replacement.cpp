#include <bits/stdc++.h>
using namespace std;

// Brute. T.C -> O(N*N*26), S.C -> O(1).
// int characterReplacement(string s, int k)
// {
//     int maxLength = 0;
//     for (int i = 0; i < s.length(); i++)
//     {
//         vector<int> freq(26, 0);
//         int maxFreq = 0;
//         for (int j = i; j < s.length(); j++)
//         {
//             freq[s[j] - 'A']++;
//             maxFreq = max(maxFreq, freq[s[j] - 'A']);
//             int windowLength = j - i + 1;
//             int replace = windowLength - maxFreq;
//             if (replace <= k)
//             {
//                 maxLength = max(maxLength, windowLength);
//             }
//         }
//     }
//     return maxLength;
// }

// Better. T.C -> O(N+N), S.C -> O(26).
// int characterReplacement(string s, int k)
// {
//     unordered_map<char, int> freq;
//     int left = 0;
//     int max_freq = 0;
//     int max_len = 0;
//     for (int right = 0; right < s.length(); right++)
//     {
//         freq[s[right]]++;
//         max_freq = max(max_freq, freq[s[right]]);
//         while ((right - left + 1) - max_freq > k)
//         {
//             freq[s[left]]--;
//             left++;
//         }
//         max_len = max(max_len, right - left + 1);
//     }
//     return max_len;
// }

// Optimal. T.C -> O(N), S.C -> O(1).
int characterReplacement(string s, int k)
{
    vector<int> freq(26, 0);
    int left = 0, right = 0;
    int maxCount = 0;
    int maxLength = 0;
    while (right < s.size())
    {
        freq[s[right] - 'A']++;
        maxCount = max(maxCount, freq[s[right] - 'A']);
        while ((right - left + 1) - maxCount > k)
        {
            freq[s[left] - 'A']--;
            left++;
        }
        maxLength = max(maxLength, right - left + 1);
        right++;
    }
    return maxLength;
}

int main()
{
    string s = "AABABBA";
    int k = 1;
    cout << characterReplacement(s, k) << endl;
    return 0;
}
