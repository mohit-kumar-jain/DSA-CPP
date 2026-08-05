#include <bits/stdc++.h>
using namespace std;
/*
An ugly number is a positive integer which does not 
have a prime factor other than 2, 3, and 5.
*/

bool isUgly(int n)
{
    if (n <= 0)
        return false;
    while (n % 2 == 0)
        n /= 2;
    while (n % 3 == 0)
        n /= 3;
    while (n % 5 == 0)
        n /= 5;
    return n == 1;
}

int main() {
    bool res =  isUgly(14);
    if(res == true){
        cout << "It is a ugly number." << endl;
    }else{
        cout << "It is not a ugly number." << endl;
    }
    return 0;
}