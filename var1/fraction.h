#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <stdexcept>

class Fraction {
private:
    int numerator;
    int denominator;

    void simplify();
    int findGCD(int a, int b);

public:
    Fraction();
    Fraction(int num, int den);
    
    void input();
    void display() const;

    Fraction add(const Fraction& other) const;
    Fraction subtract(const Fraction& other) const;
    Fraction multiply(const Fraction& other) const;
    Fraction divide(const Fraction& other) const;

    int getNumerator() const;
    int getDenominator() const;

    void setNumerator(int num);
    void setDenominator(int den);

    double toDecimal() const;
};

#endif