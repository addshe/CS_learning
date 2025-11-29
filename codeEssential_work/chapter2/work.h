#ifndef WORK_H
#define WORK_H
#include <iostream>
#include <vector>
#include <string>

inline bool is_size_ok(int n){
    return (n <= 0 || n > 1024);
}

const std::vector<int>* pentagonal_seq(int n = 0);

void display_message(const std::string &msg, int size = 0);

void search(int search_value, const std::vector<int>* (*func)(int) = 0);

template<typename elemType>
void display_message(const std::vector<elemType> &vec, const std::string &msg = "Types of sequences"){
      
    for(int ix = 0; ix < vec.size(); ++ix){
        std::cout << vec[ix] << ' ';
    }
    std::cout << std::endl;
    std::cout << msg;
}

void max
#endif // WORK_H