#ifndef GENERICPROGRAMMING_H
#define GENERICPROGRAMMING_H

#include<vector>
#include<string>
#include<iostream>
#include<list>

template<typename elemType>
const elemType* find(const std::vector<elemType> &vec, const elemType &value){
    for(int ix = 0; ix < vec.size(); ++ix){
        if(vec[ix] == value){
            return &vec[ix];
        }
    }
    return nullptr;
}

template<typename elemType>
const elemType* find(const elemType* array, int size, const elemType &value){
    if(!array || size < 1){
        return nullptr;
    }

    /*
    for(int ix = 0; ix < size; ++ix, ++array){
        if(*array == value){
            return array;
        }
    }
    */

    for(int ix = 0; ix < size; ++ix){
        if(array[ix] == value){
            return &array[ix];
        }
    }

    return nullptr;
}

template<typename elemType>
const elemType* find_1st(const elemType* begin, const elemType* end, const elemType &value){
    if(!begin || !end || begin >= end){//从begin遍历到end且begin，end都不为空
        return nullptr;
    }

    for(const elemType* ptr = begin; ptr != end; ++ptr){
        if(*ptr == value){
            return ptr;
        }
    }
    return nullptr;
}

// iterator+template
template<typename elemType>
void display(const std::vector<elemType> &vec, std::ostream &os){
    typename std::vector<elemType>::const_iterator iter = vec.begin();
    typename std::vector<elemType>::const_iterator end_it = vec.end();
    for(; iter != end_it; ++iter){
        os << *iter << ' ';
    }
    os << std::endl;
}

template<typename IteratorType, typename elemType>
IteratorType find(IteratorType first, IteratorType last, const elemType &value){
    for(; first != last; ++first)
        if(value == *first)
            return first;
    return last;
}

#endif // GENERICPROGRAMMING_H