#include<iostream>
#include<queue>

void Display(std::queue<char> copyQ){
    //create a copy of the queue
    std::queue<char> temp(copyQ);
    //loop until empty
    while(!temp.empty()){
        std::cout<<temp.front()<<" "<<std::endl;
        //dequeue the front
        temp.pop();
    }
        //display the front
        std::cout<<"Current Front is: "<<copyQ.front()<<std::endl;
    //add a new line
    std::cout<<std::endl;
}

int main(){
    //create an object:
    std::queue<char>myQ;

    //use the enqueue operation
    myQ.push('M');
    myQ.push('A');
    myQ.push('R');
    myQ.push('C');
    std::cout<<"Current Front is: "<<myQ.front()<<std::endl;
    std::cout<<"Current Back is: "<<myQ.back()<<std::endl;

    //prototyping
    Display(myQ);

    //use the dequeue operation
    myQ.pop();
    Display(myQ);
    myQ.pop();
    Display(myQ);
    myQ.pop();
    Display(myQ);
    myQ.pop();
    
    std::cout<<"Is the Queue Empty? "<<myQ.empty()<<std::endl;

    return 0;

}