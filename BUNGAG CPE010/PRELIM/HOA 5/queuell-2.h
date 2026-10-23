#ifndef QUEUELL
#define QUEUELL

//create a class node
template <typename T>
class qNode{
    public:
        T data;
        qNode* next;
};
//new node creator
template <typename T>
qNode<T>* new_node(T newData){
    //allocate a space for the new node
    qNode<T>* newNode = new qNode<T>;
    //store the newdata to the newNode
    newNode->data = newData;
    //point the newNode to the next
    newNode->next = nullptr;
    return newNode;
}

// enqueue
template <typename T>
void Enqueue(T newData, qNode<T>** frontPtr, qNode<T>** backPtr){
    //create a new node
    qNode<T>* newNode = new_node(newData);
    //check is the queue is empty
    if((*frontPtr) == nullptr && (*backPtr) == nullptr){
        (*frontPtr) = newNode;
        (*backPtr) = newNode;
        return;
    }
    //if not then insert at the back
    (*backPtr)->next = newNode;
    (*backPtr) = newNode;
}
//dequeue
template <typename T>
void Dequeue (qNode<T>** frontPtr, qNode<T>** backPtr){
    //check if the queue is empty
    if((*frontPtr) == nullptr && (*backPtr) == nullptr){
        std::cout<<"The Queue is Empty"<<std::endl;
        return;
    }
    // create a temporaray variable to store the node to be deleted
    qNode<T>* deleteTemp = nullptr;
    //assign the current fron to the deleteTmep
    deleteTemp = (*frontPtr);
    //check if the queue has only 1 item
    if((*frontPtr)->next == nullptr && (*backPtr)->next == nullptr){
        //means only 1 item is inside the queue
        (*frontPtr) = nullptr;
        (*backPtr) = nullptr;
        delete deleteTemp;
        return;
    }
    (*frontPtr) = (*frontPtr)->next;
    deleteTemp->next = nullptr;
    //delete the node
    delete deleteTemp;
}

//display all
template <typename T>
void DisplayQ(qNode<T>* frontPtr){
    if(frontPtr == nullptr){
        std::cout<<"The Queue Does Not Exist"<<std::endl;
    }
    while(frontPtr != nullptr){
        std::cout<<frontPtr->data;
        frontPtr = frontPtr->next;
    }
}

//isEmpty
template <typename T>
bool isEmptyQ(qNode<T>* frontPtr, qNode<T>* backPtr){
    if(frontPtr == nullptr && backPtr == nullptr){
        std::cout<<"The Queue is Empty"<<std::endl;
        return true;
    }
    return false;
}
#endif