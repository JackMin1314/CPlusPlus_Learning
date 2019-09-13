/**
*@FileName   : file_operator
*@Author     : Chen Wang
*@Version    : C++、Linux
*@Description:
*@Time       : 2019-09-12
*@Software   : QT5.9.8/Linux
*@Contact    : 1416825008@qq.com
*@Blog       : https://github.com/JackMin1314/Learning_Skill
*代 码 仅 限 学 习 ，严 禁 商 业 用 途，转 载 请 注 明 出 处
*/

#include"file_functions.h"
#include<stdio.h>

void create_iofstream(const char* filename, string data)
{

    cout<<"请写入文件..."<<endl;
    // 写的模式打开文件
    ofstream outf;
    outf.open(filename);
    getchar();
    // 舍弃使用gets()的原因是不安全，会有缓冲区溢出,有的编译器不通过
    getline(cin,data);
    outf<<data<<endl;
    outf.close();// 关闭文件以使其重新变为可访问的状态
    cout<<"写入文件结束..."<<endl;

    sleep(1);

    cout<<"开始读取文件..."<<endl;
    // 读的模式打开文件
    ifstream inf;
    inf.open(filename);
    inf.good()?cout<<"The file has been opened without problems"<<endl:cout<<"An Error has happend on opening the file"<<endl;
    while (inf>>data) { cout<<data; }
    cout<<endl;
    inf.close();// 关闭文件
    cout<<"读取文件结束..."<<endl;

}

void create_fstream(const char* filename, string data)
{
    cout<<"请写入文件..."<<endl;
    // 读写的模式打开文件
    fstream f;
    f.open(filename, ios::in|ios::out|ios::trunc);// ios::trunc 打开文件并清空内容,否则会逐字覆盖内容
    f.good()?cout<<"Success opened without problems"<<endl:cout<<"An Error has happend on opening the file"<<endl;
    getline(cin,data);
    f<<data<<endl;
    f.close();
    cout<<"写入文件结束..."<<endl;

    sleep(1);

    cout<<"开始读取文件..."<<endl;
    // 读写的模式打开文件
    f.open(filename,ios::in|ios::out);
    f.good()?cout<<"The file has been opened without problems"<<endl:cout<<"An Error has happend on opening the file"<<endl;
    while (f>>data) { cout<<data; }
    cout<<endl;
    f.close();// 关闭文件
    cout<<"读取文件结束..."<<endl;

}
