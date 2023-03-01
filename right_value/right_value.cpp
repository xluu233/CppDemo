#include <iostream>
#include <functional>

using namespace std;

namespace Dialog
{

    void apply_font(std::function<void (int&)> &&apply){
        cout << "apply_font()" <<endl;
        int res = 0;
        apply(res);
    }

}

int main(){

    Dialog::apply_font([=](int& res) -> void{
        cout << "res = " << res <<endl;
    });

    return 0;
}