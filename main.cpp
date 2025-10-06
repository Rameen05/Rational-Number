#include <iostream>
#include "RationalNumber.h"
using namespace std;

int main() {
    RationalNumber r1(10, 5);   // simplifies to 2/1
    RationalNumber r2(36, 6);   // simplifies to 6/1

    cout << "x = " << r1 << endl;
    cout << "y = " << r2 << endl;

    cout << "x + y = " << r1 + r2 << endl;
    cout << "x - y = " << r1 - r2 << endl;
    cout << "x * y = " << r1 * r2 << endl;
    cout << "x / y = " << r1 / r2 << endl;

    cout << boolalpha;
    cout << "x == y? " << (r1 == r2) << endl;
    cout << "x < y? " << (r1 < r2) << endl;

    return 0;
}
