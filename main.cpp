#include<bits/stdc++.h>
#include "headers/first_util.h"  // include header
using namespace std;

int main() {
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;
    int gcd = getGCD(a, b);
    cout << "GCD of " << a << " and " << b << " is: " << gcd << endl;
    return 0;
}