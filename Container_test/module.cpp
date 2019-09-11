/**
*@FileName   : container
*@Author     : Chen Wang
*@Version    : C++��Linux
*@Description:
* ���һЩ������ʵ�֣��������������һЩ������
*@Time       : 2019-09-07
*@Software   : QT5.9.8/Linux
*@Contact    : 1416825008@qq.com
*@Blog       : https://github.com/JackMin1314/Learning_Skill
*�� �� �� �� ѧ ϰ ���� �� �� ҵ �� ;��ת �� �� ע �� �� ��
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

// ��ʼ����ĳ�Ա����
Community::Community(){cout<<"���ù��캯��"<<endl;}
Community::~Community(){cout<<"������������"<<endl;}
// ����С������ʱ��
void  Community::setname(string str, string date){Community_name=str;community_buildtime=date;}
// ��ȡС������ʱ��
void Community::getname(void){cout<<"The name of community is  "<<Community_name<<endl;
                              cout<<"The building time of community is  "<<community_buildtime<<endl;}

/*module��س�ʼ������*/
// ��ʼ��С��ģ��
void init_community_module(Community& comm)
{
    //static Community& comm = Community::get();
    cout<<"������С�������ƺͽ���ʱ��"<<endl;
    string name,build_time;
    cin>>name>>build_time;
    // ��ȡС�������ֺͽ���ʱ��
    comm.setname(name,build_time);
    // ��ʼ��¥��Ϣ
    init_building_module(comm);

}

// ��ʼ��¥��ģ��
void init_building_module(Community& cmut)
{
    int i = 0, j = 0;
    Building temp;
    for (i = 0;  i< cmut.building_count; i++) {
        cout<<"һ��   "<< cmut.building_count<<"��¥,  ������� "<<i+1<<" ��¥���"<<endl;
        cin>>temp.Building_id;
        for (j =0; j<MAX_Floor_NUM;j++) {
            cout<<"һ��   "<<MAX_Floor_NUM<<"��¥,  ������� "<<temp.Building_id<<" ��¥���"<<"�ĵ�" <<j+1<<"����"<<endl;
            cin>>temp.FL[j].Floor_id;
        }
        // ������һ��¥��Ϣ����vector
        cmut.bd.push_back(temp);

    }
}

// ���С��������Ϣ
void show_all_community(Community& cmut)
{
    int   j = 0;
    cmut.getname();
    cout<<"С������¥����:  "<<cmut.building_count<<endl;
    cout<<"һ��   "<<cmut.bd.size()<<"��¥"<<endl;
    for (vector<Building>::iterator i = cmut.bd.begin();  i< cmut.bd.end(); i++) {
        cout<<"���е� "<<i->Building_id<<" ��¥"<<endl;
        for (j =0; j<MAX_Floor_NUM;j++) {
            cout<<"��" <<j+1<<"����Ϊ"<<i->FL[j].Floor_id<<"\t";
        }
        cout<<endl;
    }

}

/*����һЩ������ش���,ǰ���Ѿ���ʼ��module*/
// ����set����
void create_set(Community& cmut, set<Building>& bd_set){
    Building tmp;
    for (vector<Building>::iterator it = cmut.bd.begin();it != cmut.bd.end();it++) {
        tmp.Building_id = it->Building_id;
        for (int j = 0; j < MAX_Floor_NUM; j++) {
            tmp.FL[j].Floor_id = it->FL[j].Floor_id;
            tmp.FL[j].Room_count = it->FL[j].Room_count;
        }
        // bd_set.insert(tmp);

        //??? Ϊ���ܹ�Building�ṹ��Ƚϴ�С����set������Ҫ���ء�<�� ����Ͳ�ʵ�֣��ʲ�ʹ��create_set()

    }
    cout<<"create set success!! "<<endl;

}

// ����unordered_set
void create_unordered_set(Community& cmut, unordered_set<string,Building>& bd_unordered_set){
    Building tmp;
    for (vector<Building>::iterator it = cmut.bd.begin();it != cmut.bd.end();it++) {
        tmp.Building_id = it->Building_id;
        for (int j = 0; j < MAX_Floor_NUM; j++) {
            tmp.FL[j].Floor_id = it->FL[j].Floor_id;
            tmp.FL[j].Room_count = it->FL[j].Room_count;
        }
        //??? Ϊ���ܹ�Building�ṹ��Ƚϴ�С����set������Ҫ���ء�<�� ����Ͳ�ʵ�֣��ʲ�ʹ��create_unordered_set()
    }
    cout<<"create unordered_set success!! "<<endl;
}

// ����map����
void create_map(Community& cmut, map<string,Building>&bd_map){
    Building tmp;
    for (vector<Building>::iterator it = cmut.bd.begin();it != cmut.bd.end();it++) {
        tmp.Building_id = it->Building_id;
        for (int j = 0; j < MAX_Floor_NUM; j++) {
            tmp.FL[j].Floor_id = it->FL[j].Floor_id;
            tmp.FL[j].Room_count = it->FL[j].Room_count;
        }
        // ��building_id��Ϊmap���ַ���key������building��Ϊvalue
        bd_map.insert(make_pair(tmp.Building_id,tmp));
    }
    cout<<"create map success!! "<<endl;

}

// ����unordered_map
void create_unordered_map(Community& cmut, unordered_map<string,Building>&bd_unordered_map){
    Building tmp;
    for (vector<Building>::iterator it = cmut.bd.begin();it != cmut.bd.end();it++) {
        tmp.Building_id = it->Building_id;
        for (int j = 0; j < MAX_Floor_NUM; j++) {
            tmp.FL[j].Floor_id = it->FL[j].Floor_id;
            tmp.FL[j].Room_count = it->FL[j].Room_count;
        }
        // ��building_id��Ϊmap���ַ���key������building��Ϊvalue
        bd_unordered_map.insert(make_pair(tmp.Building_id,tmp));
    }
    cout<<"create unordered_map success!!"<<endl;

}
















