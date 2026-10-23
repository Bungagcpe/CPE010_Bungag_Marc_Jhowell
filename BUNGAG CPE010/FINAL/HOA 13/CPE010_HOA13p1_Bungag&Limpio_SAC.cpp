#include <iostream>
#include <thread>
using namespace std;

void bubbleSort(int arr[], int start, int end) {
    for (int i = start; i < end - 1; i++) {
        for (int j = start; j < end - 1 - (i - start); j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {9, 4, 7, 2, 8, 1, 6, 3};
    int size = 8;
    int mid = size / 2;

    cout << "Original array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    thread T1(bubbleSort, arr, 0, mid);
    thread T2(bubbleSort, arr, mid, size);

    T1.join();
    T2.join();

    int temp[8];
    int i = 0, j = mid, k = 0;

    while (i < mid && j < size) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i < mid)
        temp[k++] = arr[i++];

    while (j < size)
        temp[k++] = arr[j++];

    for (int i = 0; i < size; i++)
        arr[i] = temp[i];

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}