#ifndef FUNCTIONDECLARATION_H
#define FUNCTIONDECLARATION_H

#include <iostream>
#include <vector>
#include <fstream>
#include <vector>
#include <string>
//#include <limits>
//#include <cstdlib>

void swap(int & val1, int & val2, std::ofstream & ofil);

void bubble_sort(std::vector<int> &vec, std::ofstream & ofil);

void display(const std::vector<int>&, std::ostream& = std::cout);

template<typename elemType>
void display_message(const std::string &msg, const std::vector<elemType> & vec){
    std::cout << msg;
    for(int ix = 0; ix < vec.size(); ++ix){
        elemType t = vec[ix];
        std::cout << t << ' ';              
    }
}

void display_message(const std::string &msg, int size = 0);

/* 重载函数声明
void display(char ch);
void display(const std::string&);
void display(const std::string&, int);
void display(const std::string&, int, int);
*/

const std::vector<int>* fibon_seq(int size = 0);

//ps: 使用inline必须连带定义
inline bool seq_elem(int pos, int & elem, const std::vector<int>* (*seq_ptr)(int) = 0){
 //没有传入第三个参数时的报错
    if(!seq_ptr){
        display_message("Internal Error: seq_ptr is set to null");
        return false;
    }
//传入第三个参数后开始执行
    const std::vector<int> * pseq = seq_ptr(pos);
    if(!pseq){
        elem = 0;
        return false;
    }
    elem = (*pseq)[pos-1];//下标从零开始
    return true;
}

                              
#endif // FUNCTIONDECLARATION_H;