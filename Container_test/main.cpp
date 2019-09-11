/**
*@FileName   : container
*@Author     : Chen Wang
*@Version    : C++��Linux
*@Description:
* ����ѧϰunordered_map��unordered_set��map��set��vector����
*
*@Time       : 2019-09-07
*@Software   : QT5.13.1
*@Contact    : 1416825008@qq.com
*@Blog       : https://github.com/JackMin1314/Learning_Skill
*�� �� �� �� ѧ ϰ ���� �� �� ҵ �� ;��ת �� �� ע �� �� ��
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<typeinfo>
#include<time.h>
#include"ds_def.h"
#include"module.h"
/**
 *���롯/+**���ٻس����ú���ע��
 */
static vector<Building> bd_vector;
static unordered_map<string,Building> bd_unordered_map;
static map<string, Building> bd_map;

template<typename  T>
void print_all(const T& t)
{
    // �����vector�����Ļ� sequence container
    if (typeid (t)==typeid(vector<Building>))
    {
        cout<<"������Ϊvector<Building>"<<endl;
        // vector������μ� module.cpp�����show_all_community()
    }
    // �����unordered_map�Ļ� associative container
    if (typeid(t)==typeid (unordered_map<string,Building>))
    {
        cout<<"������Ϊ unordered_map<string,Building>"<<endl;
        show_unordered_map(bd_unordered_map);

    }
    // �����map�Ļ� associative container
    if(typeid (t)==typeid (map<string,Building>))
    {
        cout<<"������Ϊ map<string,Building>"<<endl;
        show_map(bd_map);
    }
}

using namespace std;

int main()
{
    // �������󲢳�ʼ��
    cout<<"**********�������󲢳�ʼ��***********"<<endl;
    static Community& comm = Community::get();
    init_community_module(comm);
    show_all_community(comm);
    // ��������
    cout<<"**********��������������***********"<<endl;

    // ��������
    create_map(comm,bd_map);
    create_unordered_map(comm,bd_unordered_map); // ��������Կ���unordered_map�����򡯴��

    // ��ӡ����
    cout<<"**********��ӡ����***********"<<endl;
    print_all(bd_map);
    cout<<"*********************"<<endl;
    print_all(bd_unordered_map);

    cout<<"Program Complete!!"<<endl;
    return 0;
}
