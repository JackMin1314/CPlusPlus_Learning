#ifndef MODULE_H
#define MODULE_H
#include"ds_def.h"

void init_community_module(Community& comm);
void init_building_module(Community& cmut);
void show_all_community(Community& cmut);

// 创建set容器
void create_set(Community& cmut, set <Building>&bd_set);

// 创建map容器
void create_map(Community& cmut, map<string,Building>&bd_map);

// 创建unordered_set
void create_unordered_set(Community& cmut, unordered_set<string,Building>& bd_unordered_set);

// 创建unordered_map
void create_unordered_map(Community& cmut, unordered_map<string,Building>& bd_unordered_map);

/*打印容器元素*/
// 打印vector
void show_vector(Community& cmut);

// 打印show_map
void show_map(map<string,Building>&bd_map);

// 打印show_unordered_map
void show_unordered_map(unordered_map<string,Building>&bd_unordered_map);
#endif // MODULE_H
