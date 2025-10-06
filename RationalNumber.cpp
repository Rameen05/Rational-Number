#include "RationalNumber.h"


int RationalNumber::gcd(int num_1, int num_2) {
    while (num_2 != 0) {
        int store = num_2;
        num_2 = num_1 % num_2;
        num_1 = store;
    }
    return (num_1 < 0) ? -num_1 : num_1;
}


void RationalNumber::reduce() {
    int gcd_val = gcd(numerator, denominator);
    numerator /= gcd_val;
    denominator /= gcd_val;

    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}


RationalNumber::RationalNumber(int num_1, int den_1) {
    if (den_1 == 0) {
        throw invalid_argument("0 in the denominator is not allowed");
    }
    numerator = num_1;
    denominator = den_1;
    reduce();
}


int RationalNumber::find_num() const { return numerator; }
int RationalNumber::find_den() const { return denominator; }


RationalNumber RationalNumber::operator+(const RationalNumber& other) const {
    return RationalNumber(numerator * other.denominator + other.numerator * denominator,
                          denominator * other.denominator);
}

RationalNumber RationalNumber::operator-(const RationalNumber& other) const {
    return RationalNumber(numerator * other.denominator - other.numerator * denominator,
                          denominator * other.denominator);
}

RationalNumber RationalNumber::operator*(const RationalNumber& other) const {
    return RationalNumber(numerator * other.numerator,
                          denominator * other.denominator);
}

RationalNumber RationalNumber::operator/(const RationalNumber& other) const {
    if (other.numerator == 0) {
        throw invalid_argument("Division by zero fraction.");
    }
    return RationalNumber(numerator * other.denominator,
                          denominator * other.numerator);
}


bool RationalNumber::operator==(const RationalNumber& other) const {
    return numerator == other.numerator && denominator == other.denominator;
}

bool RationalNumber::operator!=(const RationalNumber& other) const {
    return !(*this == other);
}

bool RationalNumber::operator<(const RationalNumber& other) const {
    return numerator * other.denominator < other.numerator * denominator;
}

bool RationalNumber::operator<=(const RationalNumber& other) const {
    return *this < other || *this == other;
}

bool RationalNumber::operator>(const RationalNumber& other) const {
    return !(*this <= other);
}

bool RationalNumber::operator>=(const RationalNumber& other) const {
    return !(*this < other);
}


ostream& operator<<(ostream& out, const RationalNumber& r) {
    if (r.denominator == 1)
        out << r.numerator;
    else
        out << r.numerator << "/" << r.denominator;
    return out;
} 
