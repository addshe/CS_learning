#include "work.h"

void display_message(const std::string &msg, int size){
    if(size != 0) std::cout<< msg << " : " << size << std::endl; return;
    std::cout << msg;
}

const std::vector<int>* pentagonal_seq(int n){
    if (is_size_ok(n)){
        display_message("The number is unable to be used");
        return 0;
    }

    static std::vector<int> pentagonal_arr;

    int num = 0;
    for(int ix = 1; ix <= n; ++ix){
        num = ix * (3 * ix - 1) / 2;
        pentagonal_arr.push_back(num);
    }

    //ps:这里for循环如果不想使用{}，语句必须用逗号连接,不然容易出现作用域问题！！！
    /*像这样：
    for(int ix = 1; ix <= n; ++ix){
        num = ix * (3 * ix - 1) / 2,
        pentagonal_arr.push_back(num);
    */
    return &pentagonal_arr;// 返回局部静态变量的地址
}

void search(int search_value, const std::vector<int>* (*func)(int)){
    if(func == 0){
        display_message("Function pointer is null");
        return;
    }
    if(is_size_ok(search_value)){
        display_message("The number is unable to be used");
        return;
    }
    std::cout << std::endl;
    display_message("The value with your searching is", (*func(search_value))[search_value-1]);
}

/*
int max(int a, int b){
    if(a == b) return a;
    return (a > b)? a : b;
}

float max(float a, float b){
    if(a == b) return a;
    return (a > b)? a : b;
}

int max(std::string a, std::string b){
    if(a.size() == b.size()) return a.size();
    return (a.size() > b.size())? a.size() : b.size();
}

int max(const std::vector<int> arr){
    int tmp = 0;
    for(int ix = 0; ix < arr.size(); ++ix){
        for(int jx = 0; jx < arr.size(); ++jx){
            if(arr[ix] > arr[jx]){
                tmp = arr[ix];
            }else if(arr[ix] < arr[jx]){
                tmp = arr[jx];
            }else{
                continue;
            }
        }
    }
    return tmp;
}
*/

