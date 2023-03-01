#include <iostream>
#include <string>

using namespace std;

class Clock
{
private:
    int hour;
    int minute;
    int second;
public:
    Clock(int h, int m, int s){
        if ((h >= 0 && h <= 24) && (m >= 0 && m <= 60) && (s >= 0 && s <= 60)){
            hour = h;
            minute = m;
            second = s;
        }
        else {
            cout << "time format error" <<endl;
        }
    };

    void show(){
        cout << hour << ":" << minute << ":" << second << endl;
    }


    //前端运算符
    Clock& operator++(){
        second++;
        if (second >= 60)
        {
            second = second - 60;
            minute++;
            if (minute >= 60)
            {
                minute = minute - 60;
                hour++;
                hour = hour % 24;
            }
            
        }
        return *this;
    }

    //这里的int无意义，仅代表后端运算符
    Clock operator++(int){
        Clock old = *this;
        ++(*this);
        return old;
    }

    Clock& operator--(int){
        this->second--;
        if (this->second < 0)
        {
            this->second += 60;
            this->minute--;
            if (this->minute < 0)
            {
                this->minute += 60;
                this->hour--;
                if (this->hour < 0)
                {
                    this->hour += 24;
                }
                this->hour %= 24;
            }
        }
        return *this;
    }


};

int main() {
    Clock time(12,59,59);
    time.show();

    //这里的int无意义
    time.operator++(2);
    time.show();

    time++;
    time.show();

    ++time;
    time.show();

    for (size_t i = 0; i < 60; i++)
    {
        ++time;
    }
    time.show();

    cout << "-----------------" << endl;

    time--;
    time.show();
    
    //减少一分钟
    for (size_t i = 0; i < 60; i++)
    {
        time--;
    }
    time.show();

    // 减少一小时
    for (size_t i = 0; i < 60*60; i++)
    {
        time--;
    }
    time.show();


    cout << "-----------------" << endl;


    Clock time2(1,0,0);
    //time2.show();

    for (size_t i = 0; i < 60*60*24; ++i)
    {
        if (i%60 == 0)
        {
            time2.show();
        }
        time2--;
    }
    time2.show();

}

