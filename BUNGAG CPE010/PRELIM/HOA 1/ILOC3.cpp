/*ILO 3*/
#include<iostream>
#include<cmath>

float DistanceFormula(float x1, float x2, float y1, float y2){
    return sqrt(pow(x2 - x1, 2)+pow(y2 - y1, 2));
}

int main(){
    float x1, x2, y1, y2, Distance;
    std::cout<<"Enter Value for X1: ";
    std::cin>> x1;
    std::cout<<"Enter Value for X2: ";
    std::cin>> x2;
    std::cout<<"Enter Value for Y1: ";
    std::cin>> y1;
    std::cout<<"Enter Value for Y2: ";
    std::cin>> y2;

    Distance = DistanceFormula(x1, x2, y1, y2);

    std::cout<<"The Distance Between Two points is: "<<Distance<<"\n";

    return 0;
}
