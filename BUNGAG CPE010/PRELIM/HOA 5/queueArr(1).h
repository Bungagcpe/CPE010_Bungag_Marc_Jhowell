#ifndef QUEUEARR_H
#define QUEUEARR_H
#include <iostream>

//Array-Based Circular Queue
template <typename T>
class queueArr{
    private:
    //pointer to dynamically allocate array
    T* q_array;
    //maximum number of elements a queue can hold
    size_t q_capacity;
    //current number of the elements in the queue
    size_t q_size;
    //Index of the front element
    int q_front;
    //Index of the back element
    int q_back;

    public:
        queueArr(size_t capacity = 10);
        queueArr(const queueArr& other);
        queueArr& operator=(const queueArr& other);
        ~queueArr();
        //queue operations:
        bool Empty();
        bool Full();
        size_t Size();
        void Clear();
        T Front();
        T Back();
        void Enqueue(T value);
        T Dequeue();
};

//contructor
template <typename T>
queueArr<T>::queueArr(size_t MAXcap){
    q_capacity = MAXcap;
    q_size = 0;
    q_front = 0;
    q_back = -1;
    q_array = new T[q_capacity];
}

//copy contructor
template <typename T>
queueArr<T>::queueArr(const queueArr<T>& other){
    q_capacity = other.q_capacity;
    q_size = other.q_size;
    q_front = other.q_front;
    q_back = other.q_back;

    for(size_t i = 0; i < q_capacity; i++){
        q_array[i] = other.q_array[i];
    }
}
//copy assignment operator
template <typename T>
queueArr<T>& queueArr<T>::operator=(const queueArr<T>& other) {

    if (this != &other) {

        delete[] q_array;

        q_capacity = other.q_capacity;
        q_size = other.q_size;
        q_front = other.q_front;
        q_back = other.q_back;
        for (size_t i = 0; i < q_capacity; i++) {
            q_array[i] = other.q_array[i];
        }
    }
    return *this;
}
//destructor
template <typename T>
queueArr<T>::~queueArr(){
    delete[] q_array;
}

//empty
template <typename T>
bool queueArr<T>::Empty(){
    return q_size == 0;
}

//Full
template <typename T>
bool queueArr<T>::Full(){
    return q_size == q_capacity;
}

//size_T
template <typename T>
size_t queueArr<T>::Size(){
    return q_size;
}

//front
template <typename T>
T queueArr<T>::Front(){
    //check if queue is empty
    if(Empty()){
        std::cout<<"Queue is Empty\n";
        return T();
    }
    //return the fornt
    return q_array[q_front];
}

//back
template <typename T>
T queueArr<T>::Back(){
    if(Empty()){
        std::cout<<"Queue is Empty\n";
        return T();
    }
    return q_array[q_back];
}

//clear
template <typename T>
void queueArr<T>::Clear(){

    //reset the q_size, q_front, q_back
    q_size = 0;
    q_front = 0;
    q_back = -1;
}

//Enqueue
template <typename T>
void queueArr<T>::Enqueue(T value){

    //check if the queue is full
    if(Full()){
        std::cout<<"Queue is Full\n";
        return;
    }
    //move q_back circularly
    q_back = (q_back + 1) % q_capacity;
    //store the value to the back
    q_array[q_back] = value;
    //increment the q_size
    q_size++;
}

//Dequeue
template <typename T>
T queueArr<T>::Dequeue(){

    //check if the queue is empty
    if(Empty()){
        std::cout<<"Queue is Empty\n";
        return T();
    }
    //create a temp variable to store the current front
    T temp = q_array[q_front];
    //move q_front circularly
    q_front = (q_front + 1) % q_capacity;
    //decrement the q_size
    q_size--;
    //reset the indexes if the queue becomes empty
    if(Empty()) Clear();
    //return the temporary variable
    return T();
}
#endif