#include <iostream>
#include <numeric> 

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    // Constructor
    Fraction(int num, int den);

    // Overloaded addition operator
    Fraction operator+(const Fraction&) const;

    // Overloaded subtraction operator
    Fraction operator-(const Fraction&) const;

    // Overloaded multiplication operator
    Fraction operator*(const Fraction&) const;

    // Overloaded division operator
    Fraction operator/(const Fraction&) const;

    // Overloaded equality operator (==)
    bool operator==(const Fraction&) const;

    // Overload output operator (<<) for printing fractions
    friend ostream& operator<<(ostream& os, const Fraction& frac);

    // Function to simplify the fraction
    void simplify();

    // Utility functions for LCM and GCD
    static int lcm(int a, int b);
    static int gcd(int a, int b);
};

// Implementation

Fraction::Fraction(int num, int den) : numerator(num), denominator(den) {
    if (den == 0) {
        throw invalid_argument("Denominator cannot be zero");
    }
    simplify();  // Simplify upon construction
}

Fraction Fraction::operator+(const Fraction& other) const {
    int common_den = lcm(denominator, other.denominator);
    int num1 = numerator * (common_den / denominator);
    int num2 = other.numerator * (common_den / other.denominator);
    return Fraction(num1 + num2, common_den);
}

Fraction Fraction::operator-(const Fraction& other) const {
    int common_den = lcm(denominator, other.denominator);
    int num1 = numerator * (common_den / denominator);
    int num2 = other.numerator * (common_den / other.denominator);
    return Fraction(num1 - num2, common_den);
}

Fraction Fraction::operator*(const Fraction& other) const {
    return Fraction(numerator * other.numerator, denominator * other.denominator);
}

Fraction Fraction::operator/(const Fraction& other) const {
    if (other.numerator == 0) {
        throw std::invalid_argument("Cannot divide by zero");
    }
    return Fraction(numerator * other.denominator, denominator * other.numerator);
}

bool Fraction::operator==(const Fraction& other) const {
    // Compare simplified versions of both fractions
    return numerator * other.denominator == other.numerator * denominator;
}

ostream& operator<<(ostream& os, const Fraction& frac) {
    os << frac.numerator << "/" << frac.denominator;
    return os;
}

void Fraction::simplify() {
    int gcd_value = gcd(numerator, denominator);
    numerator /= gcd_value;
    denominator /= gcd_value;
    if (denominator < 0) {  // Normalize fraction to keep denominator positive
        numerator = -numerator;
        denominator = -denominator;
    }
}

int Fraction::lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int Fraction::gcd(int a, int b) {
    
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Main function for testing
int main() {
    Fraction frac1(1, 2);
    Fraction frac2(3, 4);

    Fraction sum = frac1 + frac2;
    Fraction diff = frac1 - frac2;
    Fraction prod = frac1 * frac2;
    Fraction quot = frac1 / frac2;

    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;
    cout << "Product: " << prod << endl;
    cout << "Quotient: " << quot << endl;

    if (frac1 == frac2) {
        cout << "Fractions are equal" << endl;
    } else {
        cout << "Fractions are not equal" << endl;
    }

    return 0;
}