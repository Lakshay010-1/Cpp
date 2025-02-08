#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    // Data Types
    int intVal = 9;          //  4 bytes
    char charVal = 'a';      //  1 byte
    float floatVal = 8.9f;   //  4 bytes
    bool boolVal = true;     //  1 byte  // {true returns 1} and {false returns 0}
    double douVal = 5234905; //  8 bytes
    string str="abc";        //  24 bytes

    // Data Modifiers
    long int lInt=1234;
    short int sInt=14;
    unsigned int unsignInt=12;
    signed signInt=-12;
    long long int llInt=123412421;

    // Type Conversion
    /*bool -> char -> short int -> int ->  unsigned int -> long -> unsigned -> long long -> float -> double -> long double*/
    double newDouVal = floatVal;

    // Type Casting
    int newIntVal = (int)douVal;

    // Data Input
    int inputVal;
    cout << "Enter Value" << endl;
    cin >> inputVal;
    cout << "Entered Value is : " << inputVal << endl;

    // Operators
    // (i). Arithmetic Operators i.e.,
    // Unary: Works on single operand.
    int val = 1;
    int a1 = val++,a2 = ++val;
    int b1 = val--, b2 = --val;
    // Binary: Works on two operands.
    // Operators -> +, –, *, /, %, etc.
    int sum = val + val;
    int diff = val - val;

    // (ii). Relational Operators
    //  Operators -> ==, >, >=, <, <=, etc.
    bool con=(a1==a2);

    // (iii). Logical Operators
    // Operators -> &&, ||, !, etc.
    int logCon=(sum && diff);

    // (iv). Bitwise Operators
    // Operators -> &, |, ^, <<, >>, ~, etc.
    int bitVal= 2 & 3;

    // (v). Assignment Operators
    // Operators -> =,+=, -=, *=, /=, etc.
    int onePlusVal=1;
    onePlusVal+=val;

    // (vi). Ternary or Conditional Operators
    // Operator -> Expression1 ? Expression2 : Expression3;
    int ternaryRes=(sum>diff)?1:0;

    // Math
    // (i). Built-in functions e.g.,max(), min(), etc.
    int a=5,b=9;
    int maxVal=max(a,b);
    int minVal=min(a,b);
    swap(a,b);
    // (ii). Library functions
    int sqrtVal=sqrt(9);
    int roundVal=round(3.6);
    int logVal=log(64);
    
    return 0;
}