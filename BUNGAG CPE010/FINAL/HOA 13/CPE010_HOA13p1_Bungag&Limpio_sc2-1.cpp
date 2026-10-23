#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <mutex>

std::mutex mtx;

void print(int n, const std::string &str) {
    std::string msg = std::to_string(n) + " : " + str;
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << msg << std::endl;
}

int main() {
    std::vector<std::string> s = {
        "T.I.P.",
        "Competent",
        "Computer",
        "Engineers"
    };
    std::vector<std::thread> threads;

    for (size_t i = 0; i < s.size(); i++) {
        threads.push_back(std::thread(print, static_cast<int>(i), s[i]));
    }

    for (auto &th : threads) {
        th.join();
    }
    return 0;
}