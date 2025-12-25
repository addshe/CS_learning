#include "FunctionDeclaration.h"

void swap(int & val1, int & val2, std::ofstream & ofil){
    int temp = val1;
    val1 = val2;
    val2 = temp;
    ofil << "after swap(): vall1: " << val1 << " vall2: " << val2 << "\n";
}

/*
void bubble_sort(vector<int> vec){
    for(int ix = 0; ix < vec.size(); ++ix){
        for(int jx = ix + 1; jx < vec.size(); ++jx){
            if(vec[ix] > vec[jx]){
                swap(vec[ix], vec[jx]);
            }
        }
    }
}
*/

/*
void bubble_sort(vector<int> & vec){
    for(int ix = 0; ix < vec.size(); ++ix){
        for(int jx = ix + 1; jx < vec.size(); ++jx){
            if(vec[ix] > vec[jx]){
                ofil << "about to call swap! " << "ix: " << ix << " " << "jx: " << jx << "\t" << "swaping: " << vec[ix] << " with " << vec[jx] << endl;
                swap(vec[ix], vec[jx]);
            }
        }
    }
}
*/

void bubble_sort(std::vector<int> &vec, std::ofstream & ofil){
    for(int ix = 0; ix < vec.size(); ++ix){
        for(int jx = ix + 1; jx < vec.size(); ++jx){
            if(vec[ix] > vec[jx]){
                ofil << "about to call swap! " << "ix: " << ix << " " << "jx: " << jx << "\t" << "swaping: " << vec[ix] << " with " << vec[jx] << std::endl;
                swap(vec[ix], vec[jx], ofil);
            }
        }
    }
}

//**********************************************************

void display(const std::vector<int> & vec, std::ostream & os){
    for(int ix = 0; ix < vec.size(); ++ix){
        os << vec[ix] << ' ';
    }
    os << std::endl;
}
/* 重载函数实现
void display(char ch){
    std::cout << ch << std::endl;
}

void display(const std::string& str){
    std::cout << str << std::endl;
}

void display(const std::string& str, int){
    for(int ix = 0; ix < str.size(); ++ix){
        std::cout << str[ix] << ' ';
    }
    std::cout << std::endl;
}
*/

void display_message(const std::string &msg, int size){
    std::cout << msg << " : " << size << std::endl;
}


bool is_size_ok(int size){
    const int max_size = 1024;
    const std::string msg("Requested size is not supported.");
    if(size < 0 || size > max_size){
        display_message(msg, size);
        return false;
    }
    return true;
}

//斐波那契数列
const std::vector<int>* fibon_seq(int size){

    const int max_size = 1024;
    static std::vector<int> elems;

    if(!is_size_ok(size)){
        return 0;
    }

    for(int ix = elems.size(); ix < size; ++ix){
        if(ix == 0){
            elems.push_back(0);
        } else if (ix == 1){
            elems.push_back(1);
        } else {
            elems.push_back(elems[ix - 1] + elems[ix - 2]);
        }
    }

    return &elems;
}
