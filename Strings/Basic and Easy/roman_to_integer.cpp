#include<bits/stdc++.h>       
using namespace std;

// Optimal. T.C. -> O(n), S.C. -> O(1).

int roman(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }
    return 0;
}

int romanToInteger(string s){
    int sum = 0,index = 0;
    while(index < s.size() - 1){
        if(roman(s[index]) < roman(s[index + 1])){
            sum -= roman(s[index]);
            index++;
        }else{
            sum += roman(s[index]);
            index++;
        }
    }
    sum += roman(s[index]);

    return sum;
}

int main() {
    string s = "LXXX";
    cout << romanToInteger(s) << endl;
    return 0;
}