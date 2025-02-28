#include<iostream>
#include<exception>
#include<fstream>
#include<ctime>
using namespace std;

// fstream library includes 3 classes : 
//   (i). ofstream  - Creates and writes to files
//  (ii). ifstream  - Reads from files
// (iii). fstream   - creates, reads, and writes to files (combination of ofstream and ifstream)

// When an error occurs, C++ will normally stop and generate an error message. The technical term for this is: exception.
// Exception handling in C++ consist of three keywords: try, throw and catch.

int main(){

    cout<<"Approach-1. Using ofstream and ifstream : "<<endl;
    // Create and open a text file
    ofstream MyFile("filename_01.txt");

    // Write to the file
    MyFile<<"lorem ipsum \nlorem ipsum \nlorem ipsum \nlorem ipsum";

    // Close the file
    MyFile.close();
    
    // Read from the text file
    ifstream MyReadFile("filename_01.txt");

    // Create a text string, which is used to output the text file 
    string myText;

    // Use a while loop together with the getline() function to read the file line by line
    while (getline (MyReadFile, myText)) {
        // Output the text from the file
        cout << myText<<endl;
    }
    
    // Close the file
    MyReadFile.close();



    cout<<"\nApproach-2. Using fstream : "<<endl;
    fstream myFile2;

    try{
        myFile2.open("filename_02.txt", ios::out);
        if (!myFile2.is_open()) {
            throw runtime_error("Error opening file for writing");
        }
    } catch(const exception& e){
        cout << e.what() << endl;
        return 1;
    }
    time_t timestamp;
    time(&timestamp);

    myFile2 <<ctime(&timestamp)<<"";
    myFile2 << "ipsum lorem ipsum \nipsum lorem ipsum \nipsum lorem ipsum \nipsum lorem ipsum";
    myFile2.close();

    try{
        myFile2.open("filename_02.txt", ios::in);
        if (!myFile2.is_open()) {
            throw runtime_error("Error opening file for reading");
        }
    } catch(...){
        cout << "Error opening file for reading Exception..." << endl;
        return 1;
    }

    string myText2;    
    while(getline(myFile2,myText2)){
        cout<<myText2<<endl;
    }
    myFile2.close();

    return 0;
}