#include<iostream>
int SumofTwoNum(int fNum, int sNum);
int isGreaterThan(float num1, float num2);
bool BooleanValues(bool A, bool B);

int SumofTwoNum(int fNum, int sNum) {
    return fNum + sNum;
}
int isGreaterThan(float num1, float num2){
    return num1 > num2;
}
bool BooleanValues(bool A, bool B){
    std::cout<<"A and B: "<< (A && B)<<std::endl;
    std::cout<<"A or B: "<< (A || B)<<std::endl;
    std::cout<<"Not A: "<< (!A) <<std::endl;
    std::cout<<"Not B: "<< (!B) <<std::endl;
    std::cout<<"A xor B: "<< (A ^ B)<<std::endl;

    return true;
}

int main() {
    std::cout<<"The of the Two Numbers is: "<<SumofTwoNum(6, 7)<<std::endl;
    std::cout<<"Is 1 Greater Than Two?: "<<isGreaterThan(1, 2)<<std::endl;
    if(BooleanValues(true, false)){
        std::cout<<"Displaying All Logical Operations"<<std::endl;

    }
    return 0;
}
