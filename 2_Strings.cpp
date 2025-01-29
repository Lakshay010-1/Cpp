#include<iostream>
#include<string>
using namespace std;

int main(){
    // Omitting Namespace, using namespace std line can be omitted and replaced with the std keyword, followed by the
    //  "::" scope resolution operator for string (and cout) objects.
    // std::myName="LKG";
    // std::cout<<"My name is "<<myName<<endl;

    // Input Strings
    // cin considers a space (whitespace, tabs, etc) as a terminating character, which means that it can only store a single word.
    string clientName;
    cout<<"Enter Client Full Name"<<endl;
    getline(cin,clientName);
    cout<<"Client Name is: "<<clientName<<endl;

    // Special Characters
    // Characters -> \', \", \\, etc.
    string specialEx="My name is \"abc\".";
    
    // Escape Characters
    // Characters -> \n, \t, etc.
    string escapeEx="My name is \t abc \t.";    

    // String Concatenation
    // (i). "+" operator
    string fName="Abc";
    string lName="xyz";
    string fullName1=fName+" "+lName;
    // (ii). append() function
    string fullName2=fName.append(lName);

    // String length
    int len1= fullName1.length();
    int len2=fullName1.size();

    // Access Strings ({String indexes start with 0.})
    // (i). Access the characters in a string by referring to its index number inside square brackets "[]"
    char charAt0=fullName1[0];
    // (ii). at() function
    char charAt1=fullName1.at(1);

    // Change String Characters
    fullName1[3]='-';

    // Strings Styles
    string str01="Namaste";     // Regular String
    char str02[]="Namaste";     // Array of characters { C-Style String }

    return 0;
}