#include <iostream>
//global declaration
#define maxCAP 10

int stackArr[maxCAP];
int topArr = -1, newData;
//prototype functions
void push();
void pop();
void top();
bool isEmpty();
bool isFull();
void DisplayStack();

int main (){
    bool looping = true;
    int choice;
    while (looping)
    {
        std::cout<<"===================""Stack Operations""===================="<<std::endl;
        std::cout<<"Enter Your Choice"<<std::endl;
        std::cout<<"1. Push"<<std::endl;
        std::cout<<"2. Pop"<<std::endl;
        std::cout<<"3. Top"<<std::endl;
        std::cout<<"4. isEmpty"<<std::endl;
        std::cout<<"5. isFull"<<std::endl;
        std::cout<<"6. Display Stack"<<std::endl;
        std::cout<<"7. Exit"<<std::endl;
        std::cout<<"==========================================================="<<std::endl;
        std::cin>>choice;

        switch(choice){
            case 1: push();
            break;
            case 2: pop();
            break;
            case 3: top();
            break;
            case 4: std::cout<<"Is Stack Empty? "<<isEmpty()<<std::endl;
            break;
            case 5: std::cout<<"Is Stack Full? "<<isFull()<<std::endl;
            break;
            case 6: std::cout<<"Stack Displaying...";
            DisplayStack();
            std::cout<<std::endl;
            case 7: looping = false;
            break;
            default: std::cout<<"Invalid Choice"<<std::endl;
            break;
        }
    }
    return 0;
}

bool isEmpty(){
    if(topArr == -1) return true;
    return false;
}
bool isFull(){
    if(topArr == maxCAP -1)return true;
    return false;
}
void push(){
    if(isFull()){
        std::cout<<"Stack Overflow"<<std::endl;
        return;
    }
    std::cout<<"Enter a New Value: "<<std::endl;
    std::cin>>newData;
    stackArr[++topArr] = newData;

}
void pop(){
    if(isEmpty()){
        std::cout<<"Stack Underflow"<<std::endl;
    }
    std::cout<<"Enter the Value being Popped: "<<stackArr[topArr]<<std::endl;
    topArr--;
}
void top(){
    if(isEmpty()){
        std::cout<<"The Stack is Empty"<<std::endl;
        return;
    }
    std::cout<<"Top Element: "<<stackArr[topArr]<<std::endl;
}
void DisplayStack(){
    for(int i = topArr; i >= 0; i--){
        std::cout<<stackArr[i]<<" ";
    }
}