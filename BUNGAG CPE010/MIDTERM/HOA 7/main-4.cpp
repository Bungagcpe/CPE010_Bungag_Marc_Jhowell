#include <iostream>
#include <cstdlib>
#include <time.h>
#include "sortingAlgo.h"

const int maxSize = 100;

void displayArray(int arr[]);

int main(){

    int unsortedArr[maxSize] = {5, 2, 9, 1, 5};
    srand(time(0));
    for(int i = 0; i < maxSize; i++){
        unsortedArr[i] = rand()% 100;
    }

    std::cout<<"Unsorted Array: \n"<<std::endl;
    displayArray(unsortedArr);

    //std::cout<<"\nBubble Sort: \n"<<std::endl;
    //bubbleSort(unsortedArr, maxSize);
    //displayArray(unsortedArr);

    //std::cout<<"\nSelection Sort: \n"<<std::endl;
    //selectionSort(unsortedArr, maxSize);
    //displayArray(unsortedArr);

    std::cout<<"\nInsertion Sort: \n"<<std::endl;
    insertionSort(unsortedArr, maxSize);
    displayArray(unsortedArr);
}

void displayArray(int arr[]) {

    for(int i = 0; i < maxSize; i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}
