#include <iostream>
#include <cstdlib>
#include <time.h>
#include "sortingAlgo.h"

const int maxSize = 100;

void displayArr(int arr[]);

int main() {
    int unsortedArr[maxSize];
    srand(time(0));
    for (int i = 0; i < maxSize; i++) {
        unsortedArr[i] = rand() % 100;
    }

    std::cout << "UnsortedArr: \n";
    displayArr(unsortedArr);

    /*std::cout << "\n Shell Sort: \n";
    shellSort(unsortedArr, maxSize);
    displayArr(unsortedArr); 

    std::cout << "\n Merge Sort: \n";
    mergeSort(unsortedArr, 0, maxSize - 1);
    displayArr(unsortedArr); */

    std::cout << "\n Quick Sort: \n";
    quickSort(unsortedArr, 0, maxSize - 1);
    displayArr(unsortedArr); 
}

void displayArr (int arr[]) {
    for (int i = 0; i < maxSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}