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

/* CTRL +A   CTRL +I   �����ʽ��
 *  һ��С���кܶධ¥����ÿ��¥��������¥��MAX_Floor_NUM�� ÿ��¥���з���Room_count
*/

// ��������¥���
#define MAX_Floor_NUM  2
// ��������С��¥����
#define MAX_BUILDING_NUM 5

// ����¥��ṹ��
typedef struct{
    string Floor_id;//����
    int Room_count = 4;//�ò㷿����
}Floor;

// ����ÿ��¥�ṹ��
typedef struct
{
    string Building_id;//¥���
    Floor  FL[MAX_Floor_NUM];//5��¥����������ʾ��5¥
}Building;
//Building* bd;
/**
 * @brief The Community class ����С����
 */
class Community
{
public:
    Community() ;
    ~Community();
    // ����һ�����Է���Community ����ĺ���
    static Community& get(void){static Community  instance; return instance;}
    // ����С�������ֺͽ���ʱ��
    void setname(string str, string date);
    // ��ȡС�����ֺͽ���ʱ��
    void getname(void);
    // С���Ľ���������
    const static int building_count = MAX_BUILDING_NUM;//��̬������Ҫ�����ʱ���ʼ��
    // ����һ��Building��������
    vector<Building> bd;

private:
    string Community_name;
    string community_buildtime;//С������ʱ��

};
#endif // DS_DEF_H
