#ifndef SINGLY_LL_H
#define SINGLY_LL_H 

template <typename T>
class SingleList {
    public:
    T data;
    SingleList<T>* next = nullptr;
};

template <typename T>
void ListTraversal(SingleList<T>* head){
    if(head == nullptr){
        std::cout<<"The List is Empty";
        return;
    }
    while(head != nullptr){
        std::cout<<head->data;
        if(head->next != nullptr){
            std::cout<<"->";
        }
        head = head->next;
    }
    std::cout<<std::endl;   

}

template <typename T>
void sllInsertHead(T newData, SingleList<T>** currentHead){
    SingleList<T>* newNode = new SingleList<T>;
    newNode->data = newData;
    newNode->next = *currentHead;
    *currentHead = newNode;
}

template <typename T>
void sllGeneralInsert(T newData, SingleList<T>* prevNode){
    if (prevNode == nullptr){
        std::cout<<"Previous Value Cannot be Null"<<std::endl;
        return;
    }
    SingleList<T>* newNode = new SingleList<T>;
    newNode->data = newData;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

template <typename T>
void sllInsertEnd(T newData, SingleList<T>** head){
    SingleList<T>* newNode = new SingleList<T>;
    SingleList<T>* currentNode = *head;
    newNode->data = newData;
    newNode->next = nullptr;

    while(currentNode->next != nullptr){
        currentNode = currentNode->next;    
    }
    currentNode->next = newNode;
}

template <typename T>
void sllDeleteNode(T findData, SingleList<T>** head){
    if(*head == nullptr) return;

    SingleList<T>* currNode = *head;
    SingleList<T>* prevNode = nullptr;

    while(currNode != nullptr && currNode->data != findData){
        prevNode = currNode;
        currNode = currNode->next;
    }
    if(currNode == nullptr){
    std::cout<<"The Data was Not Found \n"<<std::endl;
    return;
    }
    if(prevNode == nullptr){
        *head = currNode->next;
    }else{
        prevNode->next = currNode->next;
    }

    delete currNode;
}

template <typename T>
void sllDeleteList(SingleList<T> **head){
    SingleList<T>* current = *head;

    while(current != nullptr){
        SingleList<T>* temp = current;
        current = current->next;
        delete temp;
    }
    *head = nullptr;
}
#endif