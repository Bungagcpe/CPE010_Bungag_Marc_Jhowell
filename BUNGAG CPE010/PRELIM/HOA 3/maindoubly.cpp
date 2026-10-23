#include <iostream>
#include "singly_ll.h"
#include "doubly_ll.h"

int main(){
    DoubleList<char>* head = CreateNewNode('C');
    DoubleList<char>* second = CreateNewNode('P');
    DoubleList<char>* third = CreateNewNode('E');

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    std::cout<<"Testing the DLL Traversal"<<std::endl;
    dllTraverse(head);

    std::cout<<"\n";
    std::cout<<"\n";

    std::cout<<"Testing the insertion of the head node"<<std::endl;
    dllInsertHead('X', &head);
    dllTraverse(head);

    std::cout<<"\n";
    std::cout<<"\n";

    std::cout<<"Testing the insertion of the end node"<<std::endl;
    dllInsertEnd('X', head);
    dllTraverse(head);

    std::cout<<"\n";
    std::cout<<"\n";

    std::cout<<"Testing the insertion of the general node"<<std::endl;
    dllGenInsert('M', head->next->next);
    dllTraverse(head);

    std::cout<<"\n";
    std::cout<<"\n";

    std::cout<<"Testing the deletion of a node"<<std::endl;
    dllDelNode('M', &head);
    dllTraverse(head);

    std::cout<<"\n";
    std::cout<<"\n";

     std::cout<<"Testing the deletion of a node"<<std::endl;
    dllDelNode('X', &head);
    dllTraverse(head);

    std::cout<<"\n";
    std::cout<<"\n";

     std::cout<<"Testing the deletion of a node"<<std::endl;
    dllDelNode('X', &head);
    dllTraverse(head);
}