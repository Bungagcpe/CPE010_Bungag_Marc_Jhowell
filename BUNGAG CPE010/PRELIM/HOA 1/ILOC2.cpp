/*ILO 2*/
#include<iostream>

float KtoF(float kelvin)
{
    return (kelvin - 273.15) * 9 / 5 + 32;

}
int main(){
    float Kelvin, Farenheit;

    std::cout<<"Enter the Temperature in Kelvin: ";
    std::cin>>Kelvin;

    Farenheit = KtoF(Kelvin);

    std::cout<<"The Temperature in Farenheit is: " <<Farenheit<<"F"<<"\n";

    return 0;
}