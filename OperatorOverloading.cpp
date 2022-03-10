#include <iostream>

using namespace std;

class Fraction
{

public:
    int numerator;
    int denominator;

    Fraction(int num, int denom)
    {
        numerator = num;
        denominator = denom;
    }

    //* like any other function, operators have signature
    // **  <Return Type> operatopr + (Type const & operand1, Type const & operand2);
    Fraction operator+(Fraction const &operand2)
    {

        if (this->denominator != operand2.denominator)
        {
            cout << " cannot add the fractions";
            Fraction emptyFraction(-1, -1);
            return emptyFraction;
        }
        int numSum = this->numerator + operand2.numerator;

        Fraction sumFrac(numSum, operand2.denominator);
        return sumFrac;
    }

    Fraction operator-(Fraction const &operand1)
    {

        if (this->denominator != operand1.denominator)
        {
            cout << " cannot add the fractions";
            Fraction emptyFraction(-1, -1);
            return emptyFraction;
        }

        int sub = this->numerator - operand1.numerator;
        Fraction subFrac(sub, operand1.denominator);
        return subFrac;
    }

    Fraction operator*(Fraction const &operand1)
    {

        int multNum = this->numerator * operand1.numerator;
        int multDenom = this->denominator * operand1.denominator;

        Fraction multFrac(multNum, multDenom);
        return multFrac;
    }

    Fraction operator/(Fraction const &operand1)
    {
        int newNum = this->numerator * operand1.denominator;
        int newDenom = this->denominator * operand1.numerator;
        Fraction quotFrac(newNum, newDenom);
        return quotFrac;
    }

    bool operator==(Fraction const &operand1) // * define your own behavior of the operator == , but using the common noted ( == )
    {
        if (this->numerator == operand1.numerator && this->denominator == operand1.denominator)
            return true;
        return false;
    }

    bool operator>(Fraction const &operand1)
    {
        float actualFraction1 = (float)this->numerator / this->denominator;
        float operandFraction = (float)operand1.numerator / operand1.denominator;
        if (actualFraction1 > operandFraction)
            return true;
        return false;
    }

    bool operator<(Fraction const &operand1)
    {
        float actualFraction1 = (float)this->numerator / this->denominator;
        float operandFraction = (float)operand1.numerator / operand1.denominator;
        if (actualFraction1 < operandFraction)
            return true;
        return false;
    }
 

    // * is a valid fraction, invalid fractions is divided by 0
    bool operator!(){
        if(this->denominator == 0){
            return false;
        }
        return true;
    }

    bool operator>=(Fraction const &operand1)
    {
        if ((*this) > operand1 || (*this) == operand1)
            return true;
        return false;
    }

    void print()
    {
        cout << numerator << "/" << denominator << endl;
    }
};

int main()
{

    Fraction f1(4, 9);
    Fraction f2(3, 9);

    // ** f1.+(f2)

    Fraction sum = f1 + f2;
    Fraction sub = f1 - f2;
    Fraction mult = f1 * f2;
    Fraction quot = f1 / f2;

    if (f1 < f2)
    {
        cout << "F1 is less than F2\n";
    }
    else if (f1 > f2)
    {
        cout << "F1 is greater than F2\n";
    }
    else if (f1 == f2)
    {
        cout << "F1 is equal to F2\n";
    }

    //** f1.!();
    if(!f1){
        cout<<"F1 is valid fraction\n";
    }else{
        cout<<"F1 is not valid fraction\n";
    }
    
    sum.print();
    sub.print();
    mult.print();
    quot.print();

    return 0;
}