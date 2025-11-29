#include "GenericAlgorithms.h"

/*构建斐波那契数列计算函数*/
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

bool grow_vec(std::vector<int> &vec, int elem){
    if(vec.empty()){
        vec.push_back(1);
        vec.push_back(1);
    }
    while (vec.back() < elem){
        int next_fib = vec[vec.size() - 1] + vec[vec.size() - 2];
        vec.push_back(next_fib);
    }
    return (vec.back() == elem);
}

std::vector<int> filter(const std::vector<int> &vec, int filter_value, bool (*pred)(int, int)){
    std::vector<int> nvec;
    for(int ix = 0; ix < vec.size(); ++ix){
        if(pred(vec[ix], filter_value))
            nvec.push_back(vec[ix]);
    }
    return nvec;
}

std::vector<int> filter(const std::vector<int> &vec, int value, std::less<int> &lt){
    std::vector<int> nvec;
    std::vector<int>::const_iterator iter = vec.begin();
    while ((iter = std::find_if(iter, vec.end(), /*std::bind2nd(lt, value)*/[&lt, value](int x) {return lt(x, value);})) != vec.end())
    {
        nvec.push_back(*iter);
        iter++;
    }
    return nvec;
}

//filter函数的泛型版本在头文件
void Use_Filter(){
    const int elem_size = 8;

    int ia[elem_size] = {12, 8, 43, 0, 6, 21, 3, 7};
    std::vector<int> ivec(ia, ia+elem_size);

    int ia2[elem_size];
    std::vector<int> ivec2(elem_size);

    std::cout << "filtering integer array for values less than 8\n";
    filter(ia, ia+elem_size, ia2, elem_size, std::less<int>());

    std::cout << "filtering integer array for values greater than 8\n";
    filter(ivec.begin(), ivec.end(), ivec2.begin(), elem_size, std::greater<int>());
}

int count_occurs(const std::vector<int> &vec, int val){
    std::vector<int>::const_iterator iter = vec.begin();
    int occurs_count = 0;
    /* #include <algorithm> find返回一个iterator，指向元素值为val的元素。若未找到任何符合条件的元素，就返回一个等同于vec.end()的iterator */
    while((iter = find(iter, vec.end(), val)) != vec.end()){
        ++occurs_count;
        ++iter;
    }
    return occurs_count;
}
