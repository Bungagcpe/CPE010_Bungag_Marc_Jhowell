#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>
#include "JOBLL.h"

class Printer{
private:
    qNode<Job>* front;
    qNode<Job>* back;

public:
    //Constructor
    Printer(){
        front = nullptr;
        back = nullptr;
    }

    //Destructor
    ~Printer(){
        while(!isEmptyQ(front, back)){
            Dequeue(&front, &back);
        }
    }

    //Add a new job
    void AddJobPrint(Job newJob){
        Enqueue(newJob, &front, &back);
        std::cout<<"Job has been Added to the Printer"<<std::endl;
    }

    //Process one job
    void ProcessJobPrint(){
        if(isEmptyQ(front, back)){
            std::cout<<"There are No Jobs to Process"<<std::endl;
            return;
        }
        std::cout<<"\nProcessing Job..."<<std::endl;
        front->data.DisplayCredentials();
        Dequeue(&front, &back);
        std::cout<<"Job Print Completed!"<<std::endl;
    }

    //Process all jobs
    void ProcessAllPrint(){
        while(!isEmptyQ(front, back)){
            ProcessJobPrint();
        }
        std::cout<<"\nAll Jobs have been Processed"<<std::endl;
    }

    //Display all pending jobs
    void DisplayJobPrint() {
        if(isEmptyQ(front, back)){
            std::cout<<"There are No Jobs to Process"<<std::endl;
            return;
        }
        qNode<Job>* current = front;
        std::cout<<"\n===== PENDING JOBS ====="<<std::endl;
        while(current != nullptr){
            current->data.DisplayCredentials();
            std::cout<< "~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
            current = current->next;
        }
    }
};
#endif