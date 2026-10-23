#ifndef DOUBLY_LL_H
#define DOUBLY_LL_H

template <typename T>
class DoubleList{
    public:
    T data;
    DoubleList<T>* prev = nullptr;
    DoubleList<T>* next = nullptr;
};

template <typename T>
DoubleList<T> *CreateNewNode(T newData){
    DoubleList<T> *newNode = new DoubleList<T>;

    newNode->data = newData;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

template <typename T>
void dllTraverse(DoubleList<T>* currentNode){
    if(currentNode == nullptr){
        std::cout<<"The List is Empty"<<std::endl;
        return;
    }

    DoubleList<T>* tail;

    while(currentNode != nullptr){
        std::cout<<currentNode->data<<" ";
        tail = currentNode;
        currentNode = currentNode->next;
    }
    std::cout<<"\n";
   
    while(tail != nullptr){
        std::cout<<tail->data<<" ";
        tail = tail->prev;
    }
}

template <typename T>
void dllInsertHead(T newData, DoubleList<T>** currentHead){
    DoubleList<T>* newNode = CreateNewNode(newData);
    newNode->next = *currentHead;
    (*currentHead)->prev = newNode;
    (*currentHead) = newNode;
}

template <typename T>
void dllInsertEnd(T newData, DoubleList<T>* currentHead){
    DoubleList<T>* newNode = CreateNewNode(newData);

    while(currentHead->next != nullptr){
        currentHead = currentHead->next;    
    }
    currentHead->next = newNode;
    newNode->prev = currentHead;
}

template <typename T>
void dllGenInsert(T newData, DoubleList<T>* currentHead){
        if(currentHead->prev == nullptr){
            std::cout<<"Previous Value Cannot be Null"<<std::endl;
            return;
        }
    DoubleList<T>* newNode = CreateNewNode(newData);
    newNode->next = currentHead->next;
    newNode->prev = currentHead;
    currentHead->next->prev = newNode;
    currentHead->next = newNode;
}

template <typename T>
void dllDelNode(T findData, DoubleList<T>** head){
    if (*head == nullptr) return;

    DoubleList<T>* currNode = *head;

    while(currNode != nullptr && currNode->data != findData){
        currNode = currNode->next;
    }
    if(currNode == nullptr){
    std::cout<<"The Data was Not Found \n"<<std::endl;
    return;
    }
    if(currNode->prev == nullptr){
        *head = currNode->next;
    }else{
        currNode->prev->next = currNode->next;
    }
    if(currNode->next != nullptr){
        currNode->next->prev = currNode->prev;
    }

    delete currNode;
}
#endif