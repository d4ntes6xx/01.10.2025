#include "Fraction.h"
#include <cmath>


void Fraction::simplify() {
    int gcd = findGCD(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
    
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

int Fraction::findGCD(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


Fraction::Fraction() : numerator(0), denominator(1) {}

Fraction::Fraction(int num, int den) : numerator(num), denominator(den) {
    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero!");
    }
    simplify();
}


void Fraction::input() {
    std::cout << "Enter numerator: ";
    std::cin >> numerator;
    
    std::cout << "Enter denominator: ";
    std::cin >> denominator;
    
    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero!");
    }
    simplify();
}

void Fraction::display() const {
    if (denominator == 1) {
        std::cout << numerator;
    } else {
        std::cout << numerator << "/" << denominator;
    }
}

void Fraction::displayMixed() const {
    int whole = numerator / denominator;
    int remainder = abs(numerator % denominator);
    
    if (whole != 0 && remainder != 0) {
        std::cout << whole << " " << remainder << "/" << denominator;
    } else {
        display();
    }
}


Fraction Fraction::add(const Fraction& other) const {
    int newNumerator = numerator * other.denominator + other.numerator * denominator;
    int newDenominator = denominator * other.denominator;
    return Fraction(newNumerator, newDenominator);
}

Fraction Fraction::subtract(const Fraction& other) const {
    int newNumerator = numerator * other.denominator - other.numerator * denominator;
    int newDenominator = denominator * other.denominator;
    return Fraction(newNumerator, newDenominator);
}

Fraction Fraction::multiply(const Fraction& other) const {
    int newNumerator = numerator * other.numerator;
    int newDenominator = denominator * other.denominator;
    return Fraction(newNumerator, newDenominator);
}

Fraction Fraction::divide(const Fraction& other) const {
    if (other.numerator == 0) {
        throw std::invalid_argument("Division by zero!");
    }
    int newNumerator = numerator * other.denominator;
    int newDenominator = denominator * other.numerator;
    return Fraction(newNumerator, newDenominator);
}


Fraction Fraction::power(int exponent) const {
    if (exponent == 0) {
        return Fraction(1, 1);
    }
    
    Fraction result(1, 1);
    Fraction base = (exponent > 0) ? *this : this->reciprocal();
    int absExponent = abs(exponent);
    
    for (int i = 0; i < absExponent; i++) {
        result = result.multiply(base);
    }
    return result;
}

Fraction Fraction::reciprocal() const {
    if (numerator == 0) {
        throw std::invalid_argument("Cannot get reciprocal of zero!");
    }
    return Fraction(denominator, numerator);
}

Fraction Fraction::negate() const {
    return Fraction(-numerator, denominator);
}


bool Fraction::isEqual(const Fraction& other) const {
    return (numerator * other.denominator == other.numerator * denominator);
}

bool Fraction::isGreater(const Fraction& other) const {
    return (numerator * other.denominator > other.numerator * denominator);
}

bool Fraction::isLess(const Fraction& other) const {
    return (numerator * other.denominator < other.numerator * denominator);
}


int Fraction::getNumerator() const { 
    return numerator; 
}

int Fraction::getDenominator() const { 
    return denominator; 
}


void Fraction::setNumerator(int num) { 
    numerator = num; 
    simplify();
}

void Fraction::setDenominator(int den) { 
    if (den == 0) {
        throw std::invalid_argument("Denominator cannot be zero!");
    }
    denominator = den; 
    simplify();
}


double Fraction::toDecimal() const {
    return static_cast<double>(numerator) / denominator;
}