#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

#include <iostream>
#include <stdexcept>
using namespace std;

class RationalNumber {
private:
    int numerator;
    int denominator;

    int gcd(int num_1, int num_2);
    void reduce();

public:
    RationalNumber(int num_1 = 0, int den_1 = 1);

    int find_num() const;
    int find_den() const;

    RationalNumber operator+(const RationalNumber& other) const;
    RationalNumber operator-(const RationalNumber& other) const;
    RationalNumber operator*(const RationalNumber& other) const;
    RationalNumber operator/(const RationalNumber& other) const;

    bool operator==(const RationalNumber& other) const;
    bool operator!=(const RationalNumber& other) const;
    bool operator<(const RationalNumber& other) const;
    bool operator<=(const RationalNumber& other) const;
    bool operator>(const RationalNumber& other) const;
    bool operator>=(const RationalNumber& other) const;

    friend ostream& operator<<(ostream& out, const RationalNumber& r);
};

#endif
