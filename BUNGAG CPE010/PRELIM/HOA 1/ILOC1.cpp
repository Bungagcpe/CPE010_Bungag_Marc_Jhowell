/*ILO 1*/
#include <iostream>

void SwapVar(int &var1, int &var2) {
    int temp = var1;
    var1 = var2;
    var2 = temp;
}

int main(){
    int a = 1;
    int b = 10;
    std::cout<<"Before Swapping A = "<<a<<" And B = "<<b<<"\n";

    SwapVar(a,b);
    std::cout<<"After Swapping A = "<<a<< " And B = " <<b;

    return 0;
}