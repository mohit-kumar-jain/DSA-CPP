#include<bits/stdc++.h>
using namespace std;
    
// Using XOR.
string evenOrOdd(int a){
    return  a & 1 ? "Odd" : "Even";
}

// Using Modulo.
// string evenOrOdd(int a){
//     return a % 2 ? "Odd" : "Even";
// }
                                
int main() {
    int a = 1750;
    cout << a << " is " << evenOrOdd(a) << endl;
    return 0;
}