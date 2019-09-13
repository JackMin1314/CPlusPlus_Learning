#ifndef FILE_FUNCTIONS_H
#define FILE_FUNCTIONS_H

#include<iostream>
#include<string>
#include<fstream>
#include<unistd.h> // 用来实现sleep()函数
using namespace  std;
// 创建一个用ifstream标准输出、ofstream标准输入的函数
/**
 * @brief create_iofstream 使用ifstream, ofstream
 * @param filename 保存文件名称指针
 * @param data 输入数据缓冲数组
 */
void create_iofstream(const char* filename, string data);

// 创建一个用fstream标准输入输出的函数
/**
 * @brief create_fstream 使用fstream
 * @param filename
 * @param data
 */
void create_fstream(const char* filename, string data);
#endif // FILE_FUNCTIONS_H
