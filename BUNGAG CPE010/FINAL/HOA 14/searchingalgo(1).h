#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

#include <iostream>
#include <chrono>

// Linear Search
template <typename T>
void linearSearchAR(int size, T dataFind, int array[]) {
    int comparisons = 0;
    int position = -1;

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < size; i++) {
        comparisons++;

        if (dataFind == array[i]) {
            position = i;
            break;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();

    double elapsed =
        std::chrono::duration<double, std::micro>(end - start).count();

    std::cout << "\n--- LINEAR SEARCH ---\n";
    std::cout << "n: " << size << "\n";
    std::cout << "Comparisons: " << comparisons << "\n";
    std::cout << "Result: "
              << (position != -1 ? "Found" : "Not found") << "\n";
    std::cout << "Execution time: " << elapsed << " microseconds\n";
    std::cout << "Time complexity: O(n)\n";
}

// Binary Search
template <typename T>
void binarySearchArr(T data[], int arrSize, T dataFind) {
    int low = 0;
    int high = arrSize - 1;
    int comparisons = 0;
    int position = -1;

    auto start = std::chrono::high_resolution_clock::now();

    while (low <= high) {
        int middle = low + (high - low) / 2;

        comparisons++;
        if (dataFind == data[middle]) {
            position = middle;
            break;
        }

        comparisons++;
        if (dataFind < data[middle]) {
            high = middle - 1;
        } else {
            low = middle + 1;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();

    double elapsed =
        std::chrono::duration<double, std::micro>(end - start).count();

    std::cout << "\n--- BINARY SEARCH ---\n";
    std::cout << "n: " << arrSize << "\n";
    std::cout << "Comparisons: " << comparisons << "\n";
    std::cout << "Result: "
              << (position != -1 ? "Found" : "Not found") << "\n";
    std::cout << "Execution time: " << elapsed << " microseconds\n";
    std::cout << "Time complexity: O(log n)\n";
}

#endif
