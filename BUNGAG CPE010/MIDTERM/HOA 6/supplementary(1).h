#ifndef SUPPLEMENTARY_H
#define SUPPLEMENTARY_H
#include <iostream>
#include "node.h"

//============================PROBLEM 1====================================
// Linear Search - Array
template <typename T>
void linearSearchAR(int size, T dataFind, T array[]) {
    int comparisons = 0;

    for (int i = 0; i < size; i++) {
        comparisons++;

        if (dataFind == array[i]) {
            std::cout << "Searching is successful!\n";
            std::cout << "Data found: " << array[i] << "\n";
            std::cout << "Comparisons: " << comparisons << "\n";
            return;
        }
    }

    std::cout << "Searching is unsuccessful!\n";
    std::cout << "Comparisons: " << comparisons << "\n";
}


// Linear Search - Linked List
template <typename T>
void linearSearchLL(Node<T>* nodes, T dataFind) {
    int comparisons = 0;

    while (nodes != nullptr) {
        comparisons++;

        if (nodes->data == dataFind) {
            std::cout << "Searching is successful!\n";
            std::cout << "Data found: " << nodes->data << "\n";
            std::cout << "Comparisons: " << comparisons << "\n";
            return;
        }

        nodes = nodes->next;
    }

    std::cout << "Searching is unsuccessful!\n";
    std::cout << "Comparisons: " << comparisons << "\n";
}

//============================PROBLEM 2====================================
// Sequential Search - Array
template <typename T>
int linearSearchAR(int size, T dataFind, T array[]) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] == dataFind) {
            count++;
        }
    }

    return count;
}

// Sequential Search - Linked List
template <typename T>
int linearSearchLL(Node<T>* nodes, T dataFind) {
    int count = 0;

    while (nodes != nullptr) {
        if (nodes->data == dataFind) {
            count++;
        }

        nodes = nodes->next;
    }

    return count;
}

//============================PROBLEM 4====================================

// Binary Search - Array
template <typename T>
void binarySearchArr(T data[], int arrSize, T dataFind) {
    int low = 0;
    int high = arrSize - 1;
    int middle;
    int comparisons = 0;

    while (low <= high) {
        middle = (low + high) / 2;
        comparisons++;

        if (dataFind == data[middle]) {
            std::cout << "The data was found!\n";
            std::cout << "Data found: " << data[middle] << "\n";
            std::cout << "Comparisons: " << comparisons << "\n";
            return;
        }
        else if (dataFind < data[middle]) {
            high = middle - 1;
        }
        else {
            low = middle + 1;
        }
    }

    std::cout << "The data was not found!\n";
    std::cout << "Comparisons: " << comparisons << "\n";
}

//============================PROBLEM 4====================================

// Recursive Binary Search
template <typename T>
int binarySearchRecursive(T data[], int low, int high, T dataFind, int& comparisons) {

    // Check if the search range is still valid
    if (low > high) {
        return -1;
    }

    // Find the middle element
    int middle = (low + high) / 2;
    comparisons++;

    // Check if the key is found
    if (data[middle] == dataFind) {
        return middle;
    }

    // Search the left half
    if (dataFind < data[middle]) {
        return binarySearchRecursive(data, low, middle - 1, dataFind, comparisons);
    }

    // Search the right half
    return binarySearchRecursive(data, middle + 1, high, dataFind, comparisons);
}


#endif