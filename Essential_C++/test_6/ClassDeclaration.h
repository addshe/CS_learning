#ifndef CLASSDECLARATION_H
#define CLASSDECLARATION_H

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iterator>

using std::vector;
using std::string;
using std::istream;
using std::cout;
using std::cin;
using std::endl;


// Stack
class Stack {
    public:
        bool empty();
        bool full();    
        bool push(const string&);
        bool pop(string &elem);
        bool peek(string &elem);//查看但不移除的操作
        bool find(string &str);
        int count(string &str);//返回某字符串的出现次数
        int size(){return _stack.size();};
    private:
        vector<string> _stack;
};


inline bool Stack::empty(){
    return _stack.empty();
}

inline bool Stack::full(){
    return _stack.size() == _stack.max_size();
}

/*  Triangular Number Sequence(三角数序列): 特点是第n个三角数是前n个自然数之和
    e.g: T1 = 1, T2 = 1+2 = 3, T3 = 1+2+3 = 6, T4 = 1+2+3+4 = 10, ... ;
    这里的Triangular类不是用来计算三角数的
    三角数序列是固定的数学序列,这个序列对于所有 Triangular 对象都是相同的，
    如果每个对象都保存自己的副本，会造成大量内存浪费，
    所以用static创建数组 
*/

class Triangular {
    public:
        Triangular(int len = 1, int beg = 1);
        int length() const {return _length;}
        int beg_pos() const {return _beg_pos;}
        int elem(int pos) const;
        void next_resert() const {_next = _beg_pos-1;}
        static void gen_elem_to_value(int value);
        static bool is_elem(int value);
        bool next(int &value) const;
        Triangular& copy(const Triangular &rhs);
    private:
        mutable int _next;//mutable:可修改，但受控(只能通过成员函数修改)
        int _length;//
        int _beg_pos;//开始位置
        static vector<int> _elems;
        static const int _max_elems = 1024;

};

//Triangular_iterator
class Triangular_iterator{
    public:
        Triangular_iterator(int index): _index(index-1) {};
        bool operator==(const Triangular_iterator&) const;
        bool operator!=(const Triangular_iterator&) const;
        int operator*(const Triangular_iterator &) const;
        Triangular_iterator& operator++();
        Triangular_iterator operator++(int);
    private:
        void check_integrity() const;
        int _index;
}; 

/*
    (operator==) e.g: if(trian1 == trian2), if(*ptri1 == *ptri2) ...
*/

inline bool Triangular_iterator::operator==(const Triangular_iterator &rhs) const{
    return _index == rhs._index;
}

/*
    (operator!=)
    这个函数比较的不是“两个类的成员函数和变量”，
    而是比较“当前迭代器对象”和“另一个迭代器对象（rhs）”，
    判断它们是否指向不同的位置。 返回值为bool
*/

inline bool Triangular_iterator::operator!=(const Triangular_iterator &rhs) const{
    return !(*this == rhs);
}

inline int Triangular_iterator::operator*(const Triangular_iterator &rhs) const{
    
}

//Matrix
class Matrix {
    public:
        Matrix(int row, int col):_row(row), _col(col){
            cout << "init _pmat..." << endl;
            _pmat = new double[row*col];
            cout << "Done, _pmat size: " << _row*_col*sizeof(*_pmat) << " bytes." << endl;
        }

        Matrix(const Matrix &rhs): _row(rhs._row), _col(rhs._col){
            int elem_cnt = _row*_col;
            _pmat = new double[elem_cnt];
            for(int ix = 0; ix < elem_cnt; ++ix){
                _pmat[ix] = rhs._pmat[ix];
            }
            cout << "Done, _pmat size: " << _row*_col*sizeof(*_pmat) << " bytes." << endl;
        }

        ~Matrix(){
            delete[] _pmat;
            cout << "Deleted." << endl;
        }
    private:
        int _row, _col;
        double* _pmat;
};

/*val_class

    class val_class{
        public:
            //只读访问
            const Bigclass& val() const {return _val}
            //可写访问 
            Bigclass& val() {return _val}
        private:
            Bigclass _val;
    };

    void example(const Bigclass *pbc, Bigclass *rbc){
        pbc->val();//会调用含const的val()版本
        rbc->val();//会调用无const的val()版本
    }

*/

//Other Function
void fill_stack(Stack &stack, istream &is = cin);
int sum(const Triangular &trian);
void use_sum();
void use_copy();
void use_is_elem();

#endif // CLASSDECLARATION_H;