/**
*@FileName   : container
*@Author     : Chen Wang
*@Version    : C++、Linux
*@Description:
* 用来学习unordered_map、unordered_set与map、set和vector操作
*
*@Time       : 2019-09-07
*@Software   : QT5.13.1
*@Contact    : 1416825008@qq.com
*@Blog       : https://github.com/JackMin1314/Learning_Skill
*代 码 仅 限 学 习 ，严 禁 商 业 用 途，转 载 请 注 明 出 处
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<typeinfo>
#include<time.h>
#include"ds_def.h"
#include"module.h"
/**
 *输入’/+**‘再回车启用函数注释
 */
static vector<Building> bd_vector;
static unordered_map<string,Building> bd_unordered_map;
static map<string, Building> bd_map;

template<typename  T>
void print_all(const T& t)
{
    // 如果是vector向量的话 sequence container
    if (typeid (t)==typeid(vector<Building>))
    {
        cout<<"该类型为vector<Building>"<<endl;
        // vector的输出参见 module.cpp里面的show_all_community()
    }
    // 如果是unordered_map的话 associative container
    if (typeid(t)==typeid (unordered_map<string,Building>))
    {
        cout<<"该类型为 unordered_map<string,Building>"<<endl;
        show_unordered_map(bd_unordered_map);

    }
    // 如果是map的话 associative container
    if(typeid (t)==typeid (map<string,Building>))
    {
        cout<<"该类型为 map<string,Building>"<<endl;
        show_map(bd_map);
    }
}

using namespace std;

int main()
{
    // 创建对象并初始化
    cout<<"**********创建对象并初始化***********"<<endl;
    static Community& comm = Community::get();
    init_community_module(comm);
    show_all_community(comm);
    // 创建容器
    cout<<"**********创建容器并构建***********"<<endl;

    // 构建容器
    create_map(comm,bd_map);
    create_unordered_map(comm,bd_unordered_map); // 从输出可以看到unordered_map‘乱序’存放

    // 打印容器
    cout<<"**********打印容器***********"<<endl;
    print_all(bd_map);
    cout<<"*********************"<<endl;
    print_all(bd_unordered_map);

    cout<<"Program Complete!!"<<endl;
    return 0;
}
