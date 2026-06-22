#include <bits/stdc++.h>
using namespace std;

// Optimal. T.C. -> O(1), S.C. -> O(1).
string intToRoman(int num)
{
    vector<pair<int, string>> roman = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, 
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"},
        {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };
    string res;
    for (const auto& p : roman) {
        int value = p.first;
        string symbol = p.second;

        while (num >= value) {
            res += symbol;
            num -= value;
        }
    }
    return res;
}

int main()
{
    int num = 80;
    string res = intToRoman(num);
    cout << res << endl;
    return 0;
}