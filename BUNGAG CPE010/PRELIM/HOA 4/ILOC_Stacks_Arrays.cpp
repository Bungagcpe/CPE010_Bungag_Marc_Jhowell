#include <iostream>
#include <string>

class StackArray{
private:
    static const int MAX = 10;
    char Stack[MAX];
    int Top;

public:
    StackArray(){
        Top = -1;
    }

    bool isEmpty(){
        return Top == -1;
    }

    bool isFull(){
        return Top == MAX - 1;
    }

    void Push(char Element){
        if (!isFull()){
            Stack[++Top] = Element;
        }
    }

    char Pop(){
        if (!isEmpty()){
            return Stack[Top--];
        }
        return '\0';
    }
};

bool isMatching(char Open, char Close){
    return(Open=='('&& Close ==')')||(Open=='{'&& Close=='}')||(Open=='['&&Close==']');
}

bool checkBalanced(std::string Punctuation){
    StackArray stack;

    for(char ch:Punctuation) {
        if(ch=='('||ch =='{'||ch=='['){
            stack.Push(ch);
        }
        else if(ch==')'||ch=='}'||ch==']'){
            if (stack.isEmpty()) {
                return false;
            }
            char Open = stack.Pop();
            if(!isMatching(Open, ch)) {
                return false;
            }
        }
    }
    return stack.isEmpty();
}

int main(){
    std::string Expression;

    std::cout<<"Enter an Expression: ";
    std::getline(std::cin, Expression);

    if(checkBalanced(Expression))
        std::cout<<"The Symbols are Balanced"<<std::endl;
    else
        std::cout<<"The Symbols are NOT Balanced"<<std::endl;
    return 0;
}