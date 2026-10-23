#include <iostream>
#include <string>
#include "Printer.h"

int main(){
    int ID;
    std::string Name;
    int Pages;
    Printer printer;
    int NumberOfJobs;

    std::cout<<"===== SHARED PRINTER SIMULATION ====="<<std::endl;
    std::cout<<"Enter Number of Jobs to be Printed: ";
    std::cin>>NumberOfJobs;

    for(int i = 0; i < NumberOfJobs; i++){
        std::cout<<"\nEnter Details for Job "<<i + 1<<std::endl;

        std::cout<<"Job ID: ";
        std::cin>>ID;

        std::cout<<"Username: ";
        std::cin>>Name;

        std::cout << "Number of Pages: ";
        std::cin >> Pages;

        Job newJob(ID, Name, Pages);
        printer.AddJobPrint(newJob);
    }
    printer.DisplayJobPrint();
    std::cout << "\n===== PROCESSING JOBS ====="<< std::endl;
    printer.ProcessAllPrint();

    return 0;
}