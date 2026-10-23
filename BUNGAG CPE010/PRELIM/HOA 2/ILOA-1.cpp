#include <iostream>
#include <string.h>

class Student{
private:
    std::string studentName;
    int studentAge;

public:
    //constructor
    Student(std::string newName = "John Doe", int newAge = 18) {
        studentName=std::move(newName);
        studentAge = newAge;
        std::cout << "Constructor Called."<<"\n";
    };

    //deconstrcutor
    ~Student() {
        std::cout<<"Destructor Called."<<"\n";
    }

    //Copy Constructor
    Student(const Student &copyStudent){
        std::cout<< "Copy Constructor Called."<<"\n";
        studentName = copyStudent.studentName;
        studentAge = copyStudent.studentAge;
    }

    //Copy Assignment
    Student& operator=(const Student& copyStudent){
        std::cout<<"Copy Assignment Operator Called"<<"\n";
        studentName = copyStudent.studentName;
        studentAge = copyStudent.studentAge;
        return *this;
    }

    //Display Attribute
    void printDetails(){
        std::cout<<this->studentName<< " " <<this->studentAge<<"\n";
    }
};

int main() {
   const size_t j = 5;

   Student studentList[j] = {};
   std::string namesList[j] = {"Carly", "Freddy", "Sam", "Zack", "Cody"};
   int ageList[j] = {15, 16, 18, 19, 16};

   for(size_t i = 0; i < j; i++) {
    Student *ptr = new Student(namesList[i], ageList[i]);
    studentList[i] = *ptr;
   }

   for(size_t i = 0; i < j; i++){
    studentList[i].printDetails();
   }

    return 0;
}