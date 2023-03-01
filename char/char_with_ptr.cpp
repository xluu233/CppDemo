#include <iostream>


using namespace std;

int main()
{

    //error
    // char *str = "Hello world!";

    //ok
    // const char *str = "Hello world!";

    //ok
    char* str = (char*) "Hello world!";

    cout << str << endl;


    // 因为"Hello world!"是一个固定的常量，而str是一个char类型指针，所以str赋值"Hello world!"会报错
    // 可以将"Hello world!"转为char*类型，或者申明const char* str

    return 0;
}