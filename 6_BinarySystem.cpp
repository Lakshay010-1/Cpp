#include<iostream>
#include<cmath>
using namespace std;

int decimalToBinary(int n){
    int binaryNum=0;
    int curPow=0;
    while(n>0){
        binaryNum+=pow(10,curPow) * (n%2);
        n/=2;
        curPow++;
    }
    return binaryNum;
}
int binaryToDecimal(int n){
    int decimalNum=0;
    int curPow=0;
    while(n>0){
        decimalNum+=pow(2,curPow)*(n%10);
        n/=10;
        curPow++;
    }
    return decimalNum;
}
// Get Bit
int getBit(int n,int pos){
    int bitMask=1<<pos;
    return ((n & bitMask)>0)?1:0;
}
// Set Bit
int setBit(int n,int pos){
    int bitMask=1<<pos;
    return n | bitMask;
}
// Clear Bit
int clearBit(int n,int pos){
    int bitMask=1<<pos;
    return n & ~(bitMask);
}
// Update Bit
int updateBit(int n,int bit,int pos){
    return (bit==1)?setBit(n,pos):clearBit(n,pos);
}

int main(){
    int num=10;
    int pos=1;                              // 0-indexed
    cout<<binaryToDecimal(num)<<endl;
    cout<<decimalToBinary(num)<<endl;
    cout<<getBit(num,pos)<<endl;
    int updatedBit=0;
    cout<<updateBit(num,updatedBit,pos)<<endl;
    return 0;
}