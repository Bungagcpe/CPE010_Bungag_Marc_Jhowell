#ifndef STACKLIST_H
#define STACKLIST_H

#include<iostream>

template <typename T>
class Node{
    public:
    T data;
    Node* next;
};

template <typename T>
Node<T>* head = nullptr;

template <typename T>
void push(T newData){
    Node<T>* newNode = new Node<T>();
    newNode->data = newData;

    newNode->next = head<T>;
    head<T> = newNode;
}

template <typename T>
T pop() {
    if(head<T> == nullptr){
        std::cerr<<"Stack Underflow: Cannot Pop from an Empty Stack"<<std::endl;
    }
    Node<T>* temp = head<T>;
    T tempVal = temp->data;
    head<T> = head<T>->next;
    delete temp;
    return tempVal;
}

template<typename T>
bool isEmpty(){
    return head<T> == nullptr;
}

template <typename T>
void Top() {
    if(head<T> == nullptr){
        std::cout<<"Stack is Empty. No Top Element"<<std::endl;
        return;
    }
    std::cout<<"Top Element: "<<head<T>->data<<std::endl;
}

template <typename T>
void DisplayAll(){
    if(head<T> == nullptr){
        std::cout<<"Stack Underflow\n"<<std::endl;
        return;
    }
    Node<T>* temp = head<T>;
    std::cout<<"Stack Elements: \n";
    while(temp != nullptr){
        std::cout<<temp->data<<" \n";
        temp = temp->next;
    }
    std::cout<<std::endl;
}
#endif