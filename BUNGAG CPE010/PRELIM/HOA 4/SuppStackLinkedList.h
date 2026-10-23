#ifndef STACKLINKEDLIST_H
#define STACKLINKEDLIST_H

class Node {
public:
    char data;
    Node* next;

    Node(char value);
};

class StackLinkedList {
private:
    Node* top;

public:
    StackLinkedList();
    ~StackLinkedList();

    bool isEmpty();
    void Push(char value);
    char Pop();
};

#endif