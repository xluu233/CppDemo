#include <iostream>
#include <string>

using namespace std;


class People
{
private:
    int id;
public:
    string name;
    People(const char* name, int id){
        this->name = name;
        this->id = id;
    }

    virtual void display(){
        cout << "People:" << name << "   created" << endl;
    }
    
    //纯虚函数，代表People就是抽象类
    virtual void test() = 0;
    
    //基类的析构函数一般都是虚函数
    virtual ~People(){
        cout << "people: " << name << "destoryed" << endl;
    };
};


class Manager : public People
{
private:
    int age;
    int days;
    int weeklySalary;
public:
    Manager(const char* name, int id, int age, int workDays) : People(name,id){
        this->age = age;
        this->days = workDays;
        this->weeklySalary = (days*7*100);
    }

    virtual void display(){
        cout << "Magage:" << name << "   salary" << weeklySalary << endl;
    }
    
    // 子类需要实现父类的抽象方法，如果不实现，表示子类依旧是抽象类
    void test(){

    }

    ~Manager(){
        cout << "manager: " << name << "destoryed" << endl;
    }
};

// Magage:张经理   salary4900
// saler:小李金牌销售   salary1680
// saler: 小李金牌销售destoryed
// people: 小李金牌销售destoryed
// manager: 张经理destoryed
// people: 张经理destoryed


// Magage:张经理   salary4900
// saler:小李金牌销售   salary1680
// saler: 小李金牌销售destoryed
// people: 小李金牌销售destoryed
// manager: 张经理destoryed
// people: 张经理destoryed


class SaleWorker : public People
{
private:
    int profit;
    int salary;
public:
    SaleWorker(const char* name, int id, int profit, int workDays) : People(name,id){
        this->profit = profit;
        this->salary = profit*7*workDays;
    }

    virtual void display(){
        cout << "saler:" << name << "   salary" << salary << endl;
    }

    // 子类需要实现父类的抽象方法，如果不实现，表示子类依旧是抽象类
    void test(){
    }

    ~SaleWorker(){
        cout << "saler: " << name << "destoryed" << endl;
    }
};


int main(){

    // 抽象类不能实例化
    // People people("ada",12);

    Manager manager("张经理",1,30,7);
    SaleWorker saler("小李金牌销售",2,24,10);

    People *people;
    people = &manager;
    people->display();

    people = &saler;
    people->display();



    // 多态实现
    People *people2 = new Manager("XX经理",3,30,7);
    people2->display();
    delete people2;

    return 0;
}




