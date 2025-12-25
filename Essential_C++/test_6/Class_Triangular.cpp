#include "ClassDeclaration.h"

/* 类成员变量初始化

    Triangular::Triangular(int len, int bp):_name("Triangular"){
        _length = len > 0 ? len : 1;
        _beg_pos = bp > 0 ? bp : 1;
        _next = _beg_pos-1;
    }

*/

//定义静态成员变量
int arr[4] = {6, 10, 15, 21};
vector<int> Triangular::_elems(arr,arr+4);

Triangular::Triangular(int len, int bp){
    _length = len > 0 ? len : 1;
    _beg_pos = bp > 0 ? bp : 1;
    _next = _beg_pos-1;
}

int Triangular::elem(int pos) const {
    return _elems[pos-1];
}

bool Triangular::next(int &value) const {
    if (_next < _beg_pos + _length - 1)
    {
        value = _elems[_next++];//ps:修改了内部成员函数是错误行为
        return true;
    }
    return false;
}

Triangular& Triangular::copy(const Triangular &rhs){
    if(this != &rhs){
        _length = rhs._length;
        _beg_pos = rhs._beg_pos;
        _next = rhs._beg_pos-1;
    }
    return *this;
}

bool Triangular::is_elem(int value){
    if(!_elems.size() || _elems[_elems.size()-1] < value){
        gen_elem_to_value(value);
    }
    vector<int>::iterator found_it;
    vector<int>::iterator end_it = _elems.end();

    found_it = std::find(_elems.begin(), end_it, value);
    return found_it != end_it;
}

void Triangular::gen_elem_to_value(int value){
    int ix = _elems.size();
    if(!ix){
        _elems.push_back(1);
        ix = 1;
    }
    while (_elems[ix-1] < value && ix < _max_elems)
    {
        ++ix;
        _elems.push_back(ix*(ix+1)/2);
    }
    if(ix == _max_elems){
        std::cerr << "Trangular Sequence: oops: value too large." << value << "-- execeeds max size of " << _max_elems << endl;
    }
}