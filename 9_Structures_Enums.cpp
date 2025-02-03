#include <iostream>
using namespace std;

struct myStructDataType{                                //Named Structure
        int myNum;
        string myString;
    };

int main()
{
    /*
    Structures - structs are a way to group several related variables into one place.
                 Each variable in the structure is known as a member of the structure.
    */             

    struct{                                             // Structure declaration
        int myNum;                                      // Member (int variable)
        string myString;                                // Member (string variable)
    } myStructure;                                      // Structure variable (Single or Multiple using "," to seperate variables)    

    myStructure.myNum=1;                                //Access Structrue Members using "."
    myStructure.myString="Str";

    //Storing Values
    // (i.) Approach-1.
    myStructDataType namedStructure1={1,"abc"};
    // (i.) Approach-2.
    myStructDataType namedStructure2;
    namedStructure2.myNum=2;
    namedStructure2.myString="xyz";

    /*
    Enums - enum(enumerations) is a special type that represents a group of constants (unchangeable values).
            By default, the values of the constants are constant1 = 0, constant2 = 1, constant3 = 2 and  so on.
            It cannot store float, string etc values.
            Enums are used to give names to constants, which makes the code easier to read and maintain.
            Use enums when you have values that you know aren't going to change, like month days, days, colors, deck of cards, etc.
    */
    
    enum day{                                           // enum enum-datatype-Name
        sun,            //default value=0
        mon,
        tues,
        wed='w',        //value updated
        thrus,          //value=w+1
        fri,            //value=w+2
        satur           //value=w+3
    };  
    enum day curDay =wed;                               // enum enum-datatype-Name variable-Name
    cout<<curDay<<endl;


    return 0;
}