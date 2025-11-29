#ifndef GENERICALGORITHMS_H
#define GENERICALGORITHMS_H
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>         
const std::vector<int>* fibon_seq(int size);

std::vector<int> filter(const std::vector<int> &vec, int filter_value, bool (*pred)(int, int));

inline bool less_than(int v1, int v2){
    return v1 < v2;
}
inline bool greater_than(int v1, int v2){
    return v1 > v2;
}

/*
template<typename IteratorType, typename elemType>
IteratorType find(IteratorType first, IteratorType last, const elemType &value){
    for(; first != last; ++first)
        if(value == *first)
            return first;
    return last;
}
*/

template<typename InputIterator, typename OutputIterator, typename ElemType, typename Comp>
OutputIterator filter(InputIterator first, InputIterator last, OutputIterator at, const ElemType &val, Comp pred){

    /* [&pred, &val](const auto& x) {return pred(x, val);}思路解析：

        find_if在调用std::greater<int>()后，std::greater<int>()接受两个参数。
        其中一个被固定为5，另一个是由find_if将调用的数组中的值传递给std::greater<int>()，即x。
        由std::greater<int>()将x与5作比较，返回符合条件的值。
        
    */
    while ((first = std::find_if(first, last, /*std::bind2nd(pred, val) bind2nd已经弃用*/[&pred, &val](const auto& x) {return pred(x, val);})) != last)
    {
        std::cout << "found value: " << *first << std::endl;
        *at++ = *first++;
    }
    return at;
}

#endif // GENERICALGORITHMS_H