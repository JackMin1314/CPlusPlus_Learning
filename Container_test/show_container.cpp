#include<ds_def.h>
#include<module.h>

//  display vector  在module.cpp里面show_all_community已经实现

// display map
void show_map(map<string,Building>&bd_map){
    int i=0;
    map<string, Building>::iterator it = bd_map.begin();
    while (it!=bd_map.end()) {
        cout<<"编号为："<<it->first<<"的楼栋"<<endl;
        for (i=0;i<MAX_Floor_NUM;i++) {
            cout<<"第"<<i+1<<"层编号为："<<it->second.FL[i].Floor_id<<'\t'<<endl;
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
        cout<<"编号为："<<it->first<<"的楼栋"<<endl;
        for (i=0;i<MAX_Floor_NUM;i++) {
            cout<<"第"<<i+1<<"层编号为："<<it->second.FL[i].Floor_id<<'\t'<<endl;
        }
        it++;
    }
}
