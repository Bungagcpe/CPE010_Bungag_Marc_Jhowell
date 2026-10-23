#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "searchingAlgo.h"

const int max_size = 100000;

int main() {
    int dataset[max_size];
    int newArr[max_size];

    srand(time(0));

    // Generate random numbers without displaying them
    for (int i = 0; i < max_size; i++) {
        dataset[i] = rand() % 100000;
        newArr[i] = dataset[i];
    }

    std::cout << "Random dataset generated successfully!\n";
    std::cout << "Number of elements (n): " << max_size << "\n";

    // Linear Search
    int choice;
    std::cout << "\nEnter a number to find using linear search: ";
    std::cin >> choice;

    linearSearchAR(max_size, choice, dataset);

    // Sort the copy for binary search
    std::sort(newArr, newArr + max_size);

    // Binary Search
    int binaryChoice;
    std::cout << "\nEnter a number to find using binary search: ";
    std::cin >> binaryChoice;

    binarySearchArr(newArr, max_size, binaryChoice);

    return 0;
}