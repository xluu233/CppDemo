#include <iostream>

union Student
{
    int id;
    struct Infot
    {
        char* name;
        int classname;
    } info;
    
};


int main(){

    Student student;
    student.id = 123;

    char name[] = "test";
    student.info = {name,102};

    std::cout << student.id << std::endl;
    std::cout << student.info.name << std::endl;

    return 0;
}