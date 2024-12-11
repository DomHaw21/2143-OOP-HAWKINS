/*****************************************************************************
*
*  Name:             Dominique Hawkins
*  Label:            P01
*  Title:            Fraction Class
*  Course:           CMPS 2143
*
*  Description:
*        This program implements a class that allows overeloaded operations to 
*        perfom fraction multiplication, division, addition, and subtraction.
*        It also overloads the "+" and "-" signs allowing a user to "add"
*        or "subtract" whole fractions together. It also overloads the "*" and "/" signs
*        for multiplication and division of whole fractions. It will also be able to overload ostream
*        so that it can print out the numerator and denominator of the fraction in the way we want it
*        formated.
*
*  Files:
*       main.cpp    : driver program

*****************************************************************************/
#include <iostream>
#include <numeric>
using namespace std;

//fraction class to represent fractions and perform operations on them
class Fraction {
private:
    int numerator;
    int denominator;

public:
    //constructor: Initializes the fraction with a numerator and denominator
    //throws an exception if the denominator is zero
    Fraction(int num, int den);

    //overloaded addition operator: Adds two fractions
    Fraction operator+(const Fraction&) const;

    //overloaded subtraction operator: Subtracts one fraction from another
    Fraction operator-(const Fraction&) const;

    //overloaded multiplication operator: Multiplies two fractions
    Fraction operator*(const Fraction&) const;

    //overloaded division operator: Divides one fraction by another
    //throws an exception if the second fraction's numerator is zero
    Fraction operator/(const Fraction&) const;

    //overloaded equality operator: Compares two fractions for equality
    bool operator==(const Fraction&) const;

    //friend function to overload the output operator (<<) for printing fractions
    friend ostream& operator<<(ostream& os, const Fraction& frac);

    //simplifies the fraction to its lowest terms
    void simplify();

    //function to calculate the least common multiple (LCM) of two numbers
    static int lcm(int a, int b);

    //function to calculate the greatest common divisor (GCD) of two numbers
    static int gcd(int a, int b);
};

//constructor implementation
Fraction::Fraction(int num, int den) : numerator(num), denominator(den) {
    if (den == 0) {
        throw invalid_argument("Denominator cannot be zero");
    }
    simplify(); //automatically simplify the fraction when it's created
}

//addition operator implementation
//adds two fractions using their least common multiple (LCM) as a common denominator
Fraction Fraction::operator+(const Fraction& other) const {
    int common_den = lcm(denominator, other.denominator); //finds LCM of denominators
    int num1 = numerator * (common_den / denominator);
    int num2 = other.numerator * (common_den / other.denominator);
    return Fraction(num1 + num2, common_den);
}

//subtraction operator implementation
//similar to addition but subtracts the numerators
Fraction Fraction::operator-(const Fraction& other) const {
    int common_den = lcm(denominator, other.denominator);
    int num1 = numerator * (common_den / denominator);
    int num2 = other.numerator * (common_den / other.denominator);
    return Fraction(num1 - num2, common_den);
}

//multiplication operator implementation
//multiplies the numerators and denominators directly
Fraction Fraction::operator*(const Fraction& other) const {
    return Fraction(numerator * other.numerator, denominator * other.denominator);
}

//division operator implementation
//multiplies by the reciprocal of the other fraction
Fraction Fraction::operator/(const Fraction& other) const {
    if (other.numerator == 0) { // Division by zero check
        throw std::invalid_argument("Cannot divide by zero");
    }
    return Fraction(numerator * other.denominator, denominator * other.numerator);
}

//equality operator implementation
//compares two fractions by cross-multiplication
bool Fraction::operator==(const Fraction& other) const {
    return numerator * other.denominator == other.numerator * denominator;
}

//overloaded output operator implementation
//prints a fraction in "numerator/denominator" format
ostream& operator<<(ostream& os, const Fraction& frac) {
    os << frac.numerator << "/" << frac.denominator;
    return os;
}

//simplify function implementation
//reduces the fraction to its lowest terms using GCD
void Fraction::simplify() {
    int gcd_value = gcd(numerator, denominator); //finds GCD of numerator and denominator
    numerator /= gcd_value;
    denominator /= gcd_value;

    //makes sure the denominator is always positive
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

//LCM function implementation
//returns the least common multiple of two integers
int Fraction::lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

//GCD function implementation
//returns the greatest common divisor of two integers
int Fraction::gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    Fraction frac1(1, 2);
    Fraction frac2(3, 4);

    Fraction sum = frac1 + frac2;
    Fraction diff = frac1 - frac2;
    Fraction prod = frac1 * frac2;
    Fraction quot = frac1 / frac2;

    //shows results
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
