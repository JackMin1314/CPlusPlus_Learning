/**
*@FileName   : container
*@Author     : Chen Wang
*@Version    : C++、Linux
*@Description:
* 类的一些函数的实现，构造容器，完成一些函数。
*@Time       : 2019-09-07
*@Software   : QT5.9.8/Linux
*@Contact    : 1416825008@qq.com
*@Blog       : https://github.com/JackMin1314/Learning_Skill
*代 码 仅 限 学 习 ，严 禁 商 业 用 途，转 载 请 注 明 出 处
*/

#include<iostream>
#include<string>
#include<typeinfo>
#include<vector>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include"ds_def.h"
#include"module.h"

// 初始化类的成员函数
Community::Community(){cout<<"调用构造函数"<<endl;}
Community::~Community(){cout<<"调用析构函数"<<endl;}
// 设置小区名和时间
void  Community::setname(string str, string date){Community_name=str;community_buildtime=date;}
// 获取小区名和时间
void Community::getname(void){cout<<"The name of community is  "<<Community_name<<endl;
                              cout<<"The building time of community is  "<<community_buildtime<<endl;}

/*module相关初始化代码*/
// 初始化小区模型
void init_community_module(Community& comm)
{
    //static Community& comm = Community::get();
    cout<<"请输入小区的名称和建设时间"<<endl;
    string name,build_time;
    cin>>name>>build_time;
    // 获取小区的名字和建设时间
    comm.setname(name,build_time);
    // 初始化楼信息
    init_building_module(comm);

}

// 初始化楼层模型
void init_building_module(Community& cmut)
{
    int i = 0, j = 0;
    Building temp;
    for (i = 0;  i< cmut.building_count; i++) {
        cout<<"一共   "<< cmut.building_count<<"栋楼,  请输入第 "<<i+1<<" 栋楼编号"<<endl;
        cin>>temp.Building_id;
        for (j =0; j<MAX_Floor_NUM;j++) {
            cout<<"一共   "<<MAX_Floor_NUM<<"层楼,  请输入第 "<<temp.Building_id<<" 栋楼编号"<<"的第" <<j+1<<"层编号"<<endl;
            cin>>temp.FL[j].Floor_id;
        }
        // 输入完一个楼信息存入vector
        cmut.bd.push_back(temp);

    }
}

// 输出小区所有信息
void show_all_community(Community& cmut)
{
    int   j = 0;
    cmut.getname();
    cout<<"小区最大的楼栋数:  "<<cmut.building_count<<endl;
    cout<<"一共   "<<cmut.bd.size()<<"栋楼"<<endl;
    for (vector<Building>::iterator i = cmut.bd.begin();  i< cmut.bd.end(); i++) {
        cout<<"其中第 "<<i->Building_id<<" 栋楼"<<endl;
        for (j =0; j<MAX_Floor_NUM;j++) {
            cout<<"第" <<j+1<<"层编号为"<<i->FL[j].Floor_id<<"\t";
        }
        cout<<endl;
    }

}

/*创建一些容器相关代码,前提已经初始化module*/
// 创建set容器
void create_set(Community& cmut, set<Building>& bd_set){
    Building tmp;
    for (vector<Building>::iterator it = cmut.bd.begin();it != cmut.bd.end();it++) {
        tmp.Building_id = it->Building_id;
        for (int j = 0; j < MAX_Floor_NUM; j++) {
            tmp.FL[j].Floor_id = it->FL[j].Floor_id;
            tmp.FL[j].Room_count = it->FL[j].Room_count;
        }
        // bd_set.insert(tmp);

        //??? 为了能够Building结构体比较大小，在set里面需要重载‘<’ 这里就不实现，故不使用create_set()

    }
    cout<<"create set success!! "<<endl;

}

// 创建unordered_set
void create_unordered_set(Community& cmut, unordered_set<string,Building>& bd_unordered_set){
    Building tmp;
    for (vector<Building>::iterator it = cmut.bd.begin();it != cmut.bd.end();it++) {
        tmp.Building_id = it->Building_id;
        for (int j = 0; j < MAX_Floor_NUM; j++) {
            tmp.FL[j].Floor_id = it->FL[j].Floor_id;
            tmp.FL[j].Room_count = it->FL[j].Room_count;
        }
        //??? 为了能够Building结构体比较大小，在set里面需要重载‘<’ 这里就不实现，故不使用create_unordered_set()
    }
    cout<<"create unordered_set success!! "<<endl;
}

// 创建map容器
void create_map(Community& cmut, map<string,Building>&bd_map){
    Building tmp;
    for (vector<Building>::iterator it = cmut.bd.begin();it != cmut.bd.end();it++) {
        tmp.Building_id = it->Building_id;
        for (int j = 0; j < MAX_Floor_NUM; j++) {
            tmp.FL[j].Floor_id = it->FL[j].Floor_id;
            tmp.FL[j].Room_count = it->FL[j].Room_count;
        }
        // 用building_id作为map的字符串key，整个building作为value
        bd_map.insert(make_pair(tmp.Building_id,tmp));
    }
    cout<<"create map success!! "<<endl;

}

// 创建unordered_map
void create_unordered_map(Community& cmut, unordered_map<string,Building>&bd_unordered_map){
    Building tmp;
    for (vector<Building>::iterator it = cmut.bd.begin();it != cmut.bd.end();it++) {
        tmp.Building_id = it->Building_id;
        for (int j = 0; j < MAX_Floor_NUM; j++) {
            tmp.FL[j].Floor_id = it->FL[j].Floor_id;
            tmp.FL[j].Room_count = it->FL[j].Room_count;
        }
        // 用building_id作为map的字符串key，整个building作为value
        bd_unordered_map.insert(make_pair(tmp.Building_id,tmp));
    }
    cout<<"create unordered_map success!!"<<endl;

}
















