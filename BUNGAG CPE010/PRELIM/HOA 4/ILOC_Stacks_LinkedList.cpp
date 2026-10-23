#include <iostream>
#include "SuppStackLinkedList.h"

Node::Node(char value) {
    data = value;
    next = nullptr;
}

StackLinkedList::StackLinkedList(){
    top = nullptr;
}

StackLinkedList::~StackLinkedList(){
    while (!isEmpty()){
        Pop();
    }
}

bool StackLinkedList::isEmpty(){
    return top == nullptr;
}

void StackLinkedList::Push(char value){
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
}

char StackLinkedList::Pop(){
    if (isEmpty())
        return '\0';

    Node* temp = top;
    char value = temp->data;

    top = top->next;
    delete temp;

    return value;
}

bool isMatching(char Open, char Close){
    return (Open=='('&&Close==')')||(Open=='{'&&Close=='}')||(Open=='['&&Close==']');
}

bool checkBalanced(const char Expression[]){
    StackLinkedList stack;

    for (int i = 0;Expression[i]!='\0';i++){
        char ch=Expression[i];
        if(ch=='('||ch=='{'||ch=='['){
            stack.Push(ch);
        }
        else if(ch==')'||ch=='}'||ch==']'){
            if(stack.isEmpty())
                return false;
            char Open = stack.Pop();
            if(!isMatching(Open, ch))
                return false;
        }
    }

    return stack.isEmpty();
}

int main() {

    const char* Expressions[]={
        "(A+B)+(C-D)",
        "((A+B)+(C-D)",
        "((A+B)+[C-D])",
        "((A+B]+[C-D]}"
    };

    int size=sizeof(Expressions)/sizeof(Expressions[0]);

    for (int i = 0; i < size; i++) {

        std::cout<<"Expression: "<<Expressions[i]<<std::endl;

        if(checkBalanced(Expressions[i]))
            std::cout<<"The Symbols are Balanced"<<std::endl;
        else
            std::cout<<"The Symbols are NOT Balanced"<<std::endl;
        std::cout<<std::endl;
    }

    return 0;
}