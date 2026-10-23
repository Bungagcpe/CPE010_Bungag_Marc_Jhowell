#ifndef SUPPSORTINGALGO_H
#define SUPPSORTINGALGO_H
#include <iostream>

// MERGE SORT
template <typename T>
void merge(T arr[], int left, int mid, int right) {
    T temp[100];

    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        }
        else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= right) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }
}

template <typename T>
void mergeSort(T arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}


// QUICK SORT
template <typename T>
int partition(T arr[], int low, int high) {
    T pivot = arr[low];

    int i = low + 1;
    int j = high;

    while (i <= j) {

        while (i <= high && arr[i] <= pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i < j) {
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[low], arr[j]);

    return j;
}

template <typename T>
void quickSort(T arr[], int low, int high) {
    if (low < high) {

        int position = partition(arr, low, high);

        quickSort(arr, low, position - 1);
        quickSort(arr, position + 1, high);
    }
}

#endif