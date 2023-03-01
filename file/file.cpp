#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>
using namespace std;


// 逐行读入
void readTxt1(string file)
{
    ifstream infile; 
    infile.open(file.data());   //将文件流对象与文件连接起来 或者infile.open(./xxx.txt)
    assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行 

    string s;
    while(getline(infile,s))
    {
        cout<<s<<endl;
    }
    infile.close();             //关闭文件输入流 
}


//逐个字符读入（忽略空格与回车）
void readTxt2(string file)
{
    ifstream infile; 
    infile.open(file.data());   //将文件流对象与文件连接起来 
    assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行 

    char c;
    while (!infile.eof())
    {
        infile >> c;
        cout<<c<<endl;

    }
    infile.close();             //关闭文件输入流 
}

//逐个字符读入（包括空格与回车）
void readTxt3(string file)
{
    ifstream infile; 
    infile.open(file.data());   //将文件流对象与文件连接起来 
    assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行 

    char c;
    infile >> noskipws;
    while (!infile.eof())       //达到文件末尾
    {
        infile>>c;
        cout<<c<<endl;

    }
    infile.close();             //关闭文件输入流 
}

int main(){
    // 文件路径
    string path = "D:\\test.txt";

    // 以读取模式打开文件
    ofstream inFile;
    inFile.open(path,ios::app);
    
    cout<<"输入内容："<<endl;
    string data;
    cin>>data;
    inFile<<data<<endl;
    inFile.close();

    // 读取文件
    readTxt1(path);
    
    system("pause");
    return 0;
}