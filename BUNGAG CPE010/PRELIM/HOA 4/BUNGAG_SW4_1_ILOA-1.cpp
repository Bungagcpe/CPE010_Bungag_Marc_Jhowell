#include <iostream>
#include <stack>

int main (){
    std::stack<int> stack1;
    std::stack<int> stack2;
    std::cout<<"Testing the stack STL"<<std::endl;

    //isEmpty
    std::cout<<"Is the Stack Empty? "<<stack1.empty()<<std::endl;
    
    //push
    stack1.push(10);
    std::cout<<"The top of the stack is "<<stack1.top()<<std::endl;
    stack1.push(9);
    std::cout<<"The top of the stack is "<<stack1.top()<<std::endl;
    stack1.push(8);
    std::cout<<"The top of the stack is "<<stack1.top()<<std::endl;
    stack1.push(7);
    std::cout<<"The top of the stack is "<<stack1.top()<<std::endl;
    stack1.pop();
    std::cout<<"The top of the stack will be popped out"<<std::endl;
    std::cout<<"The top of the stack is "<<stack1.top()<<std::endl;
    std::cout<<"The Size of the Stack is "<<stack1.size()<<std::endl;
    stack1.emplace(6);
    std::cout<<"The top will be replaced by "<<stack1.top()<<std::endl;

    stack2.push(10);
    std::cout<<"The top of the stack is "<<stack2.top()<<std::endl;
    stack2.push(9);
    std::cout<<"The top of the stack is "<<stack2.top()<<std::endl;
    stack2.push(8);
    std::cout<<"The top of the stack is "<<stack2.top()<<std::endl;
    stack2.push(7);
    std::cout<<"The top of the stack is "<<stack2.top()<<std::endl;

    stack1.swap(stack2);
    std::cout<<"Stack 1: "<<stack1.top()<<std::endl;
    std::cout<<"Stack 2: "<<stack2.top()<<std::endl;

    return 0;
}