#include<iostream>
#include "singly_ll.h"

int main (){
    SingleList<char>* head = nullptr;
    SingleList<char>* second = nullptr;
    SingleList<char>* third = nullptr;
    SingleList<char>* fourth = nullptr;

    head = new SingleList<char>;
    second = new SingleList<char>;
    third = new SingleList<char>;
    fourth = new SingleList<char>;
    
    head->data = 'M';
    second->data = 'A';
    third->data = 'R';
    fourth->data = 'C';

    head->next = second;
    second->next = third;    
    third->next = fourth;
    fourth->next = nullptr;

    std::cout<<"Testing of Traversal:\n";
    ListTraversal(head);

    std::cout<<"Testing of sllInsertHead:\n";
    sllInsertHead('B', &head);
    ListTraversal(head);

    std::cout<<"Testing of sllGeneralInsert:\n";
    sllGeneralInsert('X', head->next->next);
    ListTraversal(head);

    std::cout<<"Testing of sllInsertEnd:\n";
    sllInsertEnd('U', &head);
    ListTraversal(head);
    

    std::cout<<"Testing of Delete Node:\n";
    sllDeleteNode('U', &head);
    ListTraversal(head);
    sllDeleteNode('X', &head);
    ListTraversal(head);
    sllDeleteNode('B', &head);
    ListTraversal(head);

    std::cout<<"Deleting All Nodes:\n";
    sllDeleteList(&head);
    ListTraversal(head);
    return 0;
}