#include <iostream>
#include <string>

using namespace std;


struct People
{
    string name;
    int id;
};

class SalartManaege
{
private:
    int size;
    int n;
    People* people;
public:
    SalartManaege(int size = 0){
        this->size = size;
        n = 0;
        //创建size大小的数组
        people = new People[size];
    };

    int &operator[](string name){
        People *target;
        for (size_t i = 0; i < n; i++)
        {
            //已存在
            if (people[i].name == name)
            {
                return people[i].id;
            }
        }
        //指向people数组第一个空白内存处
        target = people + (n++);
        target->name = name;
        target->id = 0;
        return target->id;
    }

    ~SalartManaege(){
        delete people;
    };
};

int main(){
    SalartManaege s(3);

    string name1 = "张三";
    s[name1] = 2188;

    s["里斯"] = 1230;
    s["王无"] = 3200;
    cout << "张三\t" << s["张三"] << endl;
    cout << "里斯\t" << s["里斯"] << endl;
    cout << "王无\t" << s["王无"] << endl;

    cout << "-------下为display的输出--------\n\n";
    return 0;
}

