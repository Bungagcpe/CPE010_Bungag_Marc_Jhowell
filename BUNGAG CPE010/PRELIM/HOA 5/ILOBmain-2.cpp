#include <iostream>
#include "queuell.h"

int main (){
    qNode<char>* front = nullptr;
    qNode<char>* back = nullptr;

    std::cout<<"Testing Enqueue Operator \n";
    Enqueue('M', &front, &back);
    std::cout<<"Front: "<<front->data<<" "<<"Back: "<<back->data<<std::endl;
    Enqueue('A', &front, &back);
    std::cout<<"Front: "<<front->data<<" "<<"Back: "<<back->data<<std::endl;
    Enqueue('R', &front, &back);
    std::cout<<"Front: "<<front->data<<" "<<"Back: "<<back->data<<std::endl;
    Enqueue('C', &front, &back);
    std::cout<<"Front: "<<front->data<<" "<<"Back: "<<back->data<<std::endl;
    std::cout<<std::endl;

    std::cout<<"Displaying Queue"<<std::endl;
    DisplayQ(front);
    std::cout<<std::endl;
    std::cout<<std::endl;

    std::cout<<"Testing the Dequeue Operator \n";
    Dequeue(&front, &back);
    std::cout<<"Front: "<<front->data<<" "<<"Back: "<<back->data<<std::endl;
    Dequeue(&front, &back);
    std::cout<<"Front: "<<front->data<<" "<<"Back: "<<back->data<<std::endl;
    Dequeue(&front, &back);
    std::cout<<"Front: "<<front->data<<" "<<"Back: "<<back->data<<std::endl;
    Dequeue(&front, &back);
    Dequeue(&front, &back);
    std::cout<<std::endl;
    std::cout<<std::endl;

    std::cout<<"Testing if the Queue is Empty"<<std::endl;
    isEmptyQ(front, back);
    
    return 0;
}