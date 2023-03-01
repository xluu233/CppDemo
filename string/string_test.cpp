//
// Created by luhon on 2021/12/28.
//
#include "string"
//#include "cstring"
//#include "string.h"
//#include "strings.h"

#include "algorithm"
#include "iostream"

using namespace std;

string str = "abcdefg";

//浅拷贝
void createString(){
    string str1(str);
    string str2 = str1;
    cout << "str:" << &str << endl;
    cout << "str1:" << &str1 << endl;
    cout << "str2:" << &str2 << endl;
}

//深拷贝
void copyString(){
    string str1;

    //错误，为什么这种方式无法复制？
    //copy只负责复制，不负责申请空间，所以复制前必须有足够的空间
    std::copy(str.begin(), str.end(), str1.begin());

    //str:abcdefg  addr:0x7ff7b513a040
    cout << "str:" << str <<"  addr:" << &str << endl;
    //str1:  addr:0xb5d0dff7b0
    cout << "str1:" << str1 <<"  addr:" << &str1 << endl;

    //正确深拷贝
    string str2 = string(str);
    cout << "str2:" << str2 <<"  addr:" << &str2 << endl;

    //复制char
    char c[10];
    for (int i = 0; i < sizeof(c); ++i) {
        c[i] = 'a' + 1;
    }

    str2.copy(c,sizeof c);
    cout << "str2:" << str2 <<"  addr:" << &str2 << endl;

    string str3;
    //str3未分配空间，输出为空
    str3.copy(c,sizeof(c));
    cout << "str3:" << str3 <<"  addr:" << &str3 << endl;
}

void assignStr(){
    string str1;

    //将str赋值给str1
    str1.assign(str);
    //str:abcdefg  addr:0x7ff639f3a040
    cout << "str:" << str <<"  addr:" << &str << endl;
    //str1:abcdefg  addr:0x8c301ff830
    cout << "str1:" << str1 <<"  addr:" << &str1 << endl;

    //将"abcdef"从pos:1开始后面的2个元素赋值给str1
    str1.assign("abcdef",1,2);
    //str1:bc  addr:0x97bcdff7f0
    cout << "str1:" << str1 <<"  addr:" << &str1 << endl;

    //str从start到end-1赋值给str1
    str1.assign(str.begin(),  str.end()-1);
}

//子字符串
void subString(){
    string str1 = string (str);

    //返回pos到pos+3的字符串
    string str2 = str1.substr(0,3);
    //返回pos到结尾的字符串
    string str3 = str1.substr(4);

    //abcdefg
    cout << "str1:" << str1 << endl;
    //abc
    cout << "str2:" << str2 << endl;
    //efg
    cout << "str3:" << str3 << endl;
}

//查找和替换
void replaceStr(){
    //size:9
    string str = "abc def # abc";

    //查找，返回position, result:8
    cout << str.find('#') << endl;

    string str1 = "abc";
    auto result = str.find(str1);
    if (result != string::npos){
        //find表示第一次出现的元素，result: 0
        cout << result << endl;
    }

    //rfind是查找最后出现的元素,result: 10
    auto result2 = str.rfind(str1);
    cout << result2 << endl;

    //替换,将pos为0的后面2个元素替换为”！“
    cout << str.replace(0,2,"!")<< endl;
    //与上同理
    cout << str.replace(str.begin(),  str.end(),"ABC")<< endl;
}

//插入
void insertStr(){
    string str1 = "abc";
    string str2 = "ABC";

    //在str1中pos为1的位置插入str2,result: aABCbc
    str1.insert(1,str2);

    //在str2尾部拼接
    str2.append("GHJ");

    cout << str1 << endl;
    cout << str2 << endl;
}

//删除元素
void deleteStr(){
    //size:15
    string str = "abc  ABC ## 123";

    //删除pos为0的后面1个元素
    str.erase(0,1);
    cout << str << endl;

    //删除pos为10后面的的元素
    str.erase(10);
    cout << str << endl;

    //删除范围内的元素
    str.erase(str.end()-3,  str.end());
    cout << str << endl;
}


//替换全部元素
string replaceEmptyStr(string str,char replace){
    string::iterator iterator = str.begin();

    while (iterator != str.end()){
        iterator = std::find(str.begin(),  str.end(),replace);
        str.replace(iterator,iterator+1,"");
    }
    return str;
}

//一些乱七八糟的操作
void otherOperate(){
    string str1 = "abc ABC ##";
    string str2;

    //交换值
    //str2.swap(str1);
    swap(str1,str2);
    cout << "str1:" << str1 << "  str2:" << str2 << endl;

    //判断空
    cout << "str1:" << str1.empty() << "  str2:" << str2.empty() << endl;

    //长度,length和size好像是一样的结果
    cout << "str1:" << str1.length() << "  str2:" << str2.size() << endl;

    //最大长度,返回 string 由于保有系统或库实现限制所能保有的最大元素数
    cout << "str1:" << str1.max_size() << "  str2:" << str2.max_size() << endl;

    //capacity:当前分配的存储，即可用于存储元素的存储的容量。
    cout << "str1:" << str1.capacity() << "  str2:" << str2.capacity() << endl;

    //删除string
    str1.clear();
    for (int i = 0; i < 100; ++i) {
        str1.append("a");
    }
    //shrink_to_fit:请求减少未使用的容量
    cout << "str1:" << str1.capacity() << endl;     //120
    str1.shrink_to_fit();
    cout << "str1:" << str1.capacity() << endl;     //100

}

//类型转换
void str2Int(){
    string str1 = "45";
    string str2 = "3.14159";
    string str3 = "31337 with words";
    string str4 = "words and 2";

    int myint1 = std::stoi(str1);
    int myint2 = std::stoi(str2);
    int myint3 = std::stoi(str3);
    // 错误： 'std::invalid_argument'
    // int myint4 = std::stoi(str4);

    std::cout << "std::stoi(\"" << str1 << "\") is " << myint1 << '\n';
    std::cout << "std::stoi(\"" << str2 << "\") is " << myint2 << '\n';
    std::cout << "std::stoi(\"" << str3 << "\") is " << myint3 << '\n';
    //std::cout << "std::stoi(\"" << str4 << "\") is " << myint4 << '\n';


}

void str2long(){
    string str1 = "45";
    string str2 = "3.14159";
    string str3 = "31337435 with words";


    long mylong1 = stoul(str1);
    long mylong2 = stoul(str2);
    long long mylong3 = stoull(str3);

    std::cout << "std::stoul(\"" << str1 << "\") is " << mylong1 << '\n';
    std::cout << "std::stoull(\"" << str2 << "\") is " << mylong2 << '\n';
    std::cout << "std::stoull(\"" << str3 << "\") is " << mylong3 << '\n';

}

void str2double(){
    string str1 = "45";
    string str2 = "3.14159";
    string str3 = "31337435 with words";

    cout << stod(str1)<< endl;
    cout << stod(str2)<< endl;
    cout << stod(str3)<< endl;

//    输出：
//    45
//    3.14159
//    3.13374e+07
}

void str2float(){
    string str1 = "45";
    string str2 = "3.14159";
    string str3 = "31337435 with words";

    cout << stof(str1)<< endl;
    cout << stof(str2)<< endl;
    cout << stof(str3)<< endl;

//    45
//    3.14159
//    3.13374e+07
}

#include "unordered_set"
void strHash(){
    string str1 = "45";
    string str2 = "3.14159";
    string str3 = "31337435 with words";

    cout << "hash:" << hash<string>{}(str1) << endl;
    cout << "hash:" << hash<string>{}(str2) << endl;
    cout << "hash:" << hash<string>{}(str3) << endl;

//    hash:16962885480067938202
//    hash:10016755466282967812
//    hash:800431094397490956

}
int main(){
    str2Int();
    str2long();
    str2double();
    str2float();
    strHash();
    return 0;
}