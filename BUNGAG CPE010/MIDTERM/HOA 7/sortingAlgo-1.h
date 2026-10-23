#include <cstddef>
#include <iostream>
#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

template<typename T>
void bubbleSort(T arr[], size_t arrSize) {
    for (int i = 0; i < arrSize; i++) {
         for (int j = i + 1; j < arrSize; j++) {
            if (arr[i] > arr[j]) {
                std::swap(arr[i], arr[j]);
            }
         }
    }     
}

template <typename T>
int routineSmallest(T arr[], int K, const int arrSize) {
    int position = K;
    T smallestElem = arr[K];

    for (int j = K + 1; j < arrSize; j++) {
        if (arr[j] < smallestElem) {
            smallestElem = arr[j];
            position = j;
        }
    }
    return position;
}

template <typename T>
void selectionSort(T arr[], size_t arrSize) {
    int POS, temp, pass;
    for (int i = 0; i < arrSize; i++) {
        POS = routineSmallest(arr, i, arrSize);
        temp = arr[i];
        arr[i] = arr[POS];
        arr[POS] = temp;
        pass++;
    }
}

template <typename T>
void insertionSort(T arr[], size_t arrSize) {
    int K = 0, J, temp; 
    while (K < arrSize) {
        temp = arr[K];
        J = K - 1;
        while (temp <= arr[J]) {
            arr[J + 1] = arr[J];
            J--;
        }
        arr[J + 1] = temp;
        K++;
    }
}

#endif