#include<bits/stdc++.h>
using namespace std;
    
// Using third Varable.
// void Swap(int& a, int& b){
//     int temp = a;
//     a = b;
//     b = temp;
// }

// Without Using third Varable.
void Swap(int& a, int& b){
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}
                   
                   
int main() {
    int a = 25, b = 67;
    cout << "The value of A and B Before swapping are : " << endl;
    cout << "A : " << a << endl <<  "B : " << b << endl;
    Swap(a,b);
    cout << "The value of A and B After swapping are : " << endl;
    cout << "A : " << a << endl << "B : " << b << endl;
    return 0;
}