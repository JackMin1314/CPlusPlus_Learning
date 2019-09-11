#include<ds_def.h>
#include<module.h>

//  display vector  ��module.cpp����show_all_community�Ѿ�ʵ��

// display map
void show_map(map<string,Building>&bd_map){
    int i=0;
    map<string, Building>::iterator it = bd_map.begin();
    while (it!=bd_map.end()) {
        cout<<"���Ϊ��"<<it->first<<"��¥��"<<endl;
        for (i=0;i<MAX_Floor_NUM;i++) {
            cout<<"��"<<i+1<<"����Ϊ��"<<it->second.FL[i].Floor_id<<'\t'<<endl;
        }
        it++;
    }
}

// display unordered_map
void show_unordered_map(unordered_map<string,Building>&bd_unordered_map)
{
    int i=0;
    unordered_map<string,Building>::iterator it = bd_unordered_map.begin();
    while (it!=bd_unordered_map.end()) {
        cout<<"���Ϊ��"<<it->first<<"��¥��"<<endl;
        for (i=0;i<MAX_Floor_NUM;i++) {
            cout<<"��"<<i+1<<"����Ϊ��"<<it->second.FL[i].Floor_id<<'\t'<<endl;
        }
        it++;
    }
}
