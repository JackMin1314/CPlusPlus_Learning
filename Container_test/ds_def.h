#ifndef DS_DEF_H
#define DS_DEF_H

#include<iostream>
#include<string>

#include<vector>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<map>
//#include<list>

using namespace std;

/* CTRL +A   CTRL +I   代码格式化
 *  一个小区有很多栋楼房，每栋楼房有最大的楼层MAX_Floor_NUM， 每个楼层有房间Room_count
*/

// 定义最大的楼层号
#define MAX_Floor_NUM  2
// 定义最大的小区楼栋数
#define MAX_BUILDING_NUM 5

// 定义楼层结构体
typedef struct{
    string Floor_id;//层数
    int Room_count = 4;//该层房间数
}Floor;

// 定义每栋楼结构体
typedef struct
{
    string Building_id;//楼编号
    Floor  FL[MAX_Floor_NUM];//5个楼层容器，表示共5楼
}Building;
//Building* bd;
/**
 * @brief The Community class 创建小区类
 */
class Community
{
public:
    Community() ;
    ~Community();
    // 创建一个可以返回Community 对象的函数
    static Community& get(void){static Community  instance; return instance;}
    // 设置小区的名字和建设时间
    void setname(string str, string date);
    // 获取小区名字和建设时间
    void getname(void);
    // 小区的建筑物总数
    const static int building_count = MAX_BUILDING_NUM;//静态常量需要定义的时候初始化
    // 创建一个Building向量容器
    vector<Building> bd;

private:
    string Community_name;
    string community_buildtime;//小区建设时间

};
#endif // DS_DEF_H
