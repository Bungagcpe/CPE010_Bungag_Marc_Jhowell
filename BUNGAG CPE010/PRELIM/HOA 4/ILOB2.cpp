#include <iostream>
#include "StackList.h"

int main(){
    std::cout<<"=====PUSHING 'C' 'P' 'E' ONTO THE STACK=====\n";

    push('C');
    push('P');
    push('E');

    Top<char>;
    DisplayAll<char>();
    std::cout<<"\n === POPPING ALL ELEMENTS ===\n";

    while(!isEmpty<char>()){
        std::cout<<"Popped: "<<pop<char>()<<std::endl;
    }

    std::cout<<"\n === TESTING THE UNDERFLOW CONDIION === \n";
    pop<char>();

    return 0;
}