#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int globalVar = 0;          // Global integer
mutex mtx;                  // Protects globalVar

void add(int value) {       // Adds the parameter to the global
    lock_guard<mutex> lock(mtx);
    globalVar += value;
}

void display(const string& label) {
    lock_guard<mutex> lock(mtx);
    cout << label << globalVar << endl;
}

int main() {
    thread T1(add, 10);
    thread T2(add, 20);
    thread T3(add, 30);

    display("Display: ");
    T1.join();
    display("After T1.join(): ");
    T2.join();
    display("After T2.join(): ");
    T3.join();
    display("After T3.join(): ");
    return 0;
}