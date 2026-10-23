#include <iostream>
#include "queueArr.h"

int main(){
    //creating an object
    queueArr<int> q(5);

    // enqueue 10, 20, 30, 40, 50
    q.Enqueue(10);
    std::cout<<"Front: "<<q.Front()<<std::endl;
    std::cout<<"Back: "<<q.Back()<<std::endl;
    std::cout<<"Size: "<<q.Size()<<std::endl;
    std::cout<<std::endl;
    q.Enqueue(20);
    std::cout<<"Front: "<<q.Front()<<std::endl;
    std::cout<<"Back: "<<q.Back()<<std::endl;
    std::cout<<"Size: "<<q.Size()<<std::endl;
    std::cout<<std::endl;
    q.Enqueue(30);
    std::cout<<"Front: "<<q.Front()<<std::endl;
    std::cout<<"Back: "<<q.Back()<<std::endl;
    std::cout<<"Size: "<<q.Size()<<std::endl;
    std::cout<<std::endl;
    q.Enqueue(40);
    std::cout<<"Front: "<<q.Front()<<std::endl;
    std::cout<<"Back: "<<q.Back()<<std::endl;
    std::cout<<"Size: "<<q.Size()<<std::endl;
    std::cout<<std::endl;
    q.Enqueue(50);
    std::cout<<"Front: "<<q.Front()<<std::endl;
    std::cout<<"Back: "<<q.Back()<<std::endl;
    std::cout<<"Size: "<<q.Size()<<std::endl;
    q.Enqueue(60);
    std::cout<<std::endl;
 
    std::cout<<"Removed: "<<q.Dequeue()<<std::endl;
    std::cout<<"Removed: "<<q.Dequeue()<<std::endl;
    std::cout<<std::endl;

    q.Clear();
    std::cout << "Is the Queue Empty? "<<(q.Empty()?"Yes" : "No")<<std::endl;
    return 0;
}