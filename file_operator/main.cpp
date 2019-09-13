#include<file_functions.h>
#include<fstream>
int main()
{
    //const char* filename ="/opt/Qt_codes/file_operator/mytest.txt";// 常量定义时候就要初始化, 指定路径
    const char* filename ="./mmtest.txt";// 常量定义时候就要初始化, 在生成的build...debug文件里面
    string data = "";

    // 调用相关文件操作函数
    create_iofstream(filename, data);
    cout<<"***********************"<<data<<endl;
    create_fstream(filename, data);
    cout<<"program complete"<<endl;

    return 0;
}

