#include <iostream>
#include "suppsortingAlgo.h"

void displayArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {

    int numbers[] = {
        4, 34, 29, 48, 53,
        87, 12, 30, 44, 25,
        93, 67, 43, 19, 74
    };

    int size = 15;

    std::cout << "Original Array:\n";
    displayArr(numbers, size);

    // Merge Sort
    mergeSort(numbers, 0, size - 1);

    std::cout << "\nAfter Merge Sort:\n";
    displayArr(numbers, size);

    // Reset the array
    int numbers2[] = {
        4, 34, 29, 48, 53,
        87, 12, 30, 44, 25,
        93, 67, 43, 19, 74
    };

    // Quick Sort
    quickSort(numbers2, 0, size - 1);

    std::cout << "\nAfter Quick Sort:\n";
    displayArr(numbers2, size);

    return 0;
}