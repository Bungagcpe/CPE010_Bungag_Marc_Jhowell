#include <iostream>
#include "node.h"
#include "supplementary.h"

int main() {
//============================PROBLEM 1====================================
    // Array
    int array[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int size = 10;
    int key = 18;

    std::cout << "===== ARRAY LINEAR SEARCH =====\n";
    std::cout << "Key: " << key << "\n";

    linearSearchAR(size, key, array);


    // Linked List
    Node<int>* head = nullptr;
    Node<int>* tail = nullptr;

    int values[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};

    for (int i = 0; i < size; i++) {
        Node<int>* newNode = new_node(values[i]);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    std::cout << "\n===== LINKED LIST LINEAR SEARCH =====\n";
    std::cout << "Key: " << key << "\n";

    linearSearchLL(head, key);


    // Delete linked list
    Node<int>* current = head;

    while (current != nullptr) {
        Node<int>* temp = current;
        current = current->next;
        delete temp;
    }

//============================PROBLEM 2====================================
    int array[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int size = 10;
    int key = 18;

    // Array
    int arrayCount = linearSearchAR(size, key, array);

    std::cout << "===== ARRAY =====\n";
    std::cout << "Search key: " << key << "\n";
    std::cout << "Number of repeating instances: " << arrayCount << "\n";


    // Linked List
    Node<int>* head = nullptr;
    Node<int>* tail = nullptr;

    for (int i = 0; i < size; i++) {
        Node<int>* newNode = new_node(array[i]);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int listCount = linearSearchLL(head, key);

    std::cout << "\n===== LINKED LIST =====\n";
    std::cout << "Search key: " << key << "\n";
    std::cout << "Number of repeating instances: " << listCount << "\n";


    // Delete linked list
    Node<int>* current = head;

    while (current != nullptr) {
        Node<int>* temp = current;
        current = current->next;
        delete temp;
    }

//============================PROBLEM 3====================================

    int array[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int size = 10;
    int key = 8;

    std::cout << "===== BINARY SEARCH - ARRAY =====\n";
    std::cout << "Search key: " << key << "\n";

    binarySearchArr(array, size, key);

//============================PROBLEM 4====================================

    // Problem 3 list
    int array[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};

    int size = 10;
    int key = 8;
    int comparisons = 0;

    std::cout << "===== RECURSIVE BINARY SEARCH =====\n";
    std::cout << "Search key: " << key << "\n";

    int result = binarySearchRecursive(
        array,
        0,
        size - 1,
        key,
        comparisons
    );

    if (result != -1) {
        std::cout << "The data was found!\n";
        std::cout << "Data found: " << array[result] << "\n";
        std::cout << "Index: " << result << "\n";
        std::cout << "Comparisons: " << comparisons << "\n";
    }
    else {
        std::cout << "The data was not found!\n";
        std::cout << "Comparisons: " << comparisons << "\n";
    }

    return 0;
}